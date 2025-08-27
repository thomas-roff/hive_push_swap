/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:03:50 by thblack-          #+#    #+#             */
/*   Updated: 2025/08/25 20:39:29 by thblack-         ###   ########.fr       */
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

int	get_max_bits(unsigned int **stack)
{
	int	i;
	unsigned int	max;
	int	max_bits;

	i = 0;
	max = stack[0][0];
	max_bits = 0;
	while (stack[++i])
		if (stack[i][0] > max)
			max = stack[i][0];
	ft_printf("Max is %d\n", max);
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_unsigned_sort(unsigned int **stack_a, unsigned int **stack_b)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_uinstacklen(stack_a);
	while (i < 32)
	{
		j = 0;
		while (j < len)
		{
			stack_a[0][1] = ((stack_a[0][0] >> i) & 1);
			if (stack_a[0][1] == 1)
				uin_op_ra(stack_a, ft_uinstacklen(stack_a));
			else
				uin_op_pb(stack_a, stack_b);
			j++;
		}
		while (ft_uinstacklen(stack_b) != 0)
			uin_op_pa(stack_a, stack_b);
		i++;
	}
}

void	convert_to_signed(int **output, unsigned int **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		output[i][0] = (int)(input[i][0] ^ 0x80000000);
		i++;
	}
}

void	large_stack(int **stack, int len)
{
	unsigned int	**uin_stack_a;
	unsigned int	**uin_stack_b;

	uin_stack_a = build_uin_stack(stack, len);
	if (!uin_stack_a)
		return ;
	uin_stack_b = build_uin_stack(NULL, len);
	if (!uin_stack_b)
		return (free_and_exit_uin(uin_stack_a, NULL));
	radix_unsigned_sort(uin_stack_a, uin_stack_b);
	convert_to_signed(stack, uin_stack_a);
	free_and_exit_uin(uin_stack_a, uin_stack_b);
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
	if (!stack_a)
		return ;
	if (ft_issorted(stack_a) == 1)
		return (free_and_exit(stack_a, NULL));
	ft_printf("Input data\n");
	print_stack(stack_a);
	ft_printf("\n");
	if (len <= 5)
	{
		stack_b = build_empty_stack(len);
		if (!stack_b)
			return (free_and_exit(stack_a, NULL));
		small_stack(stack_a, stack_b, len);
	}
	else
	{
		stack_b = NULL;
		large_stack(stack_a, len);
		//radix_sort(stack_a, stack_b);
	}
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
