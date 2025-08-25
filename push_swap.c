/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:03:50 by thblack-          #+#    #+#             */
/*   Updated: 2025/08/25 19:46:52 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdint.h>

long long	ft_super_atoi(const char *nptr)
{
	long long	res;
	int			pn;
	int			digit;

	res = 0;
	pn = 1;
	while (ft_isspace((int)*nptr) == 1)
		nptr++;
	if (*nptr == '-')
	{
		pn = pn * -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (ft_isdigit((int)*nptr) == 1)
	{
		digit = *nptr - '0';
		res = res * 10 + digit;
		nptr++;
	}
	return (res * pn);
}

void	small_stack(int **stack_a, int **stack_b, int len)
{
	if (len == 2)
		op_sa(stack_a);
	if (len == 3)
		three_stack(stack_a);
	if (len == 4)
		four_stack(stack_a, stack_b);
	if (len == 5)
		five_stack(stack_a, stack_b);
}

int	neg_max_bits(int **stack)
{
	int	i;
	int	min;
	int	max_bits;

	i = 0;
	min = stack[0][0];
	max_bits = 0;
	while (stack[++i])
		if (stack[i][0] < min)
			min = stack[i][0];
	ft_printf("I got here\n");
	ft_printf("Min is %d\n", min);
	while (((unsigned int)min >> max_bits) != 0)
	{
		max_bits++;
		ft_printf("Max bits is: %d\n", max_bits);
	}
	return (max_bits);
}

int	pos_max_bits(int **stack)
{
	int	i;
	int	max;
	int	max_bits;

	i = 0;
	max = stack[0][0];
	max_bits = 0;
	while (stack[++i])
		if (stack[i][0] > max)
			max = stack[i][0];
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

int	get_max_bits(int **stack)
{
	int	neg_bits;
	int	pos_bits;

	neg_bits = neg_max_bits(stack);
	pos_bits = pos_max_bits(stack);
	if (neg_bits > pos_bits)
		return (neg_bits);
	else
		return (pos_bits);
}

void	radix_sort(int **stack_a, int **stack_b)
{
	int	i;
	int	j;
	int	max_bits;
	int	len;

	i = 0;
	max_bits = pos_max_bits(stack_a);
	len = ft_stacklen(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j < len)
		{
			stack_a[0][1] = ((stack_a[0][0] >> i) & 1);
			if (stack_a[0][1] == 1)
				op_ra(stack_a, ft_stacklen(stack_a));
			else
				op_pb(stack_a, stack_b);
			j++;
		}
		while (ft_stacklen(stack_b) != 0)
			op_pa(stack_a, stack_b);
		i++;
	}
}

void	check_build_sort(char **array)
{
	int	**stack_a;
	int	**stack_b;
	int	len;

	len = ft_arraylen(array);
	if (ft_arrcheck(array, ft_isnum) == -1 || check_dup(array) == -1
		|| len == 1)
		return ;
	stack_a = build_stack(array, len);
	stack_b = build_empty_stack(len);
	if (!stack_a || !stack_b)
		return ;
	if (ft_issorted(stack_a) == 1)
	{
		free_and_exit(stack_a, stack_b);
		return ;
	}
	ft_printf("Input data\n");
	print_stack(stack_a);
	ft_printf("\n");
	if (len <= 5)
		small_stack(stack_a, stack_b, len);
	else
		radix_sort(stack_a, stack_b);
	ft_printf("\n");
	ft_printf("Final result\n");
	print_stack(stack_a);
	free_and_exit(stack_a, stack_b);
}

char	**string_input(char *str)
{
	char		**array;

	if (!str)
		return (NULL);
	array = ft_split(str, ' ');
	if (!array)
	{
		ft_printf("ft_split error");
		return (NULL);
	}
	return (array);
}

void	free_array(char **array)
{
	while (*array)
	{
		free(*array);
		array++;
	}
}

int	main(int argc, char *argv[])
{
	char	**array;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		array = string_input(argv[1]);
		check_build_sort(array);
		free_array(array);
		free(array);
	}
	if (argc > 2)
		check_build_sort(&argv[1]);
	return (0);
}
