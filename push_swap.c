/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:03:50 by thblack-          #+#    #+#             */
/*   Updated: 2025/08/20 10:55:11 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdint.h>

int	check_dup(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 1;
		while (array[i + j])
		{
			if (ft_strcmp(array[i], array[i + j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_arrcheck(char **array, int (f)(int))
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (!f(array[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_arraylen(char **array)
{
	int	len;

	if (!array || !*array)
		return (0);
	len = 0;
	while (array[len])
		len++;
	return (len);
}

int	ft_stacklen(int **stack)
{
	int	len;
	int i;

	if (!stack || !*stack)
		return (0);
	len = 0;
	while (stack[len])
		len++;
	i = 0;
	while (stack[i])
	{
		if (stack[i][1] < 0 && i < len)
			return (i);
		i++;
	}
	return (len);
}

void	free_and_exit(int **stack_a, int **stack_b)
{
	int	i;

	i = 0;
	while (stack_a[i])
	{
		free(stack_a[i]);
		i++;
	}
	i = 0;
	while (stack_b[i])
	{
		free(stack_b[i]);
		i++;
	}
	free(stack_a);
	free(stack_b);
}

void	error_free_and_exit(int **stack, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(stack[i]);
		i++;
	}
}

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

int	ft_issorted(int **stack)
{
	int	i;

	i = 0;
	while (stack[i] && stack[i + 1])
	{
		if (stack[i][0] > stack[i + 1][0])
			return (-1);
		i++;
	}
	return (1);
}

int	**build_stack(char **array, int len)
{
	int			**stack;
	long long	temp;
	int			i;

	stack = malloc((len + 1) * sizeof(int *));
	if (!stack)
		return (NULL);
	i = 0;
	while (array[i])
	{
		stack[i] = malloc(2 * sizeof(int));
		temp = ft_super_atoi(array[i]);
		if (!stack[i] || temp > INT32_MAX || temp < INT32_MIN)
		{
			error_free_and_exit(stack, i + 1);
			free(stack);
			return (NULL);
		}
		stack[i][0] = (int)temp;
		stack[i][1] = 0;
		i++;
	}
	stack[len] = NULL;
	return (stack);
}

int	**build_empty_stack(int len)
{
	int			**stack;
	int			i;

	stack = malloc((len + 1) * sizeof(int *));
	if (!stack)
		return (NULL);
	i = 0;
	while (i < len)
	{
		stack[i] = malloc(2 * sizeof(int));
		if (!stack[i])
		{
			error_free_and_exit(stack, i + 1);
			free(stack);
			return (NULL);
		}
		stack[i][0] = 0;
		stack[i][1] = -1;
		i++;
	}
	stack[len] = NULL;
	return (stack);
}

void	print_stack(int **stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		ft_printf("Data is: %d %d\n", stack[i][0], stack[i][1]);
		i++;
	}
}

void	op_sa(int **stack)
{
	int	temp;

	temp = stack[0][0];
	stack[0][0] = stack[1][0];
	stack[1][0] = temp;
	write(1, "sa\n", 3);
}

void	op_ra(int **stack, int len)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack[0][0];
	while (++i < len)
		stack[i - 1][0] = stack[i][0];
	stack[len - 1][0] = temp;
	write(1, "ra\n", 3);
}

void	op_rra(int **stack, int len)
{
	int	temp;

	temp = stack[len - 1][0];
	while (len-- > 1)
		stack[len][0] = stack[len - 1][0];
	stack[0][0] = temp;
	write(1, "rra\n", 4);
}

void	op_pa(int **stack_a, int **stack_b)
{
	int	len_a;
	int	len_b;
	int	i;

	len_a = ft_stacklen(stack_a);
	len_b = ft_stacklen(stack_b);
	i = len_a;
	while (i-- > 0)
		stack_a[i + 1][0] = stack_a[i][0];
	stack_a[0][0] = stack_b[0][0];
	stack_a[len_a][1] = 0;
	i = 0;
	while (++i < len_b)
		stack_b[i - 1][0] = stack_b[i][0];
	stack_b[len_b - 1][0] = 0;
	stack_b[len_b - 1][1] = -1;
	write(1, "pa\n", 3);
}

void	op_pb(int **stack_a, int **stack_b)
{
	int	len_a;
	int	len_b;
	int	i;

	len_a = ft_stacklen(stack_a);
	len_b = ft_stacklen(stack_b);
	i = len_b;
	while (i-- > 0)
		stack_b[i + 1][0] = stack_b[i][0];
	stack_b[0][0] = stack_a[0][0];
	stack_b[len_b][1] = 0;
	i = 0;
	while (++i < len_a)
		stack_a[i - 1][0] = stack_a[i][0];
	stack_a[len_a - 1][0] = 0;
	stack_a[len_a - 1][1] = -1;
	write(1, "pb\n", 3);
}

void	three_stack(int **stack)
{
	if (stack[0][0] < stack[1][0] && stack[0][0] < stack[2][0]
		&& stack[1][0] > stack[2][0])
	{
		op_rra(stack, 3);
		op_sa(stack);
	}
	if (stack[0][0] > stack[1][0] && stack[0][0] < stack[2][0]
		&& stack[1][0] < stack[2][0])
		op_sa(stack);
	if (stack[0][0] < stack[1][0] && stack[0][0] > stack[2][0]
		&& stack[1][0] > stack[2][0])
		op_rra(stack, 3);
	if (stack[0][0] > stack[1][0] && stack[0][0] > stack[2][0]
		&& stack[1][0] < stack[2][0])
		op_ra(stack, 3);
	if (stack[0][0] > stack[1][0] && stack[0][0] > stack[2][0]
		&& stack[1][0] > stack[2][0])
	{
		op_ra(stack, 3);
		op_sa(stack);
	}
}

int	find_min(int **stack)
{
	int	i;
	int	min;
	int	min_index;

	if (!stack || !*stack)
		return (0);
	i = 0;
	min = stack[0][0];
	min_index = 0;
	while (stack[++i] && stack[i][1] >= 0)
		if (stack[i][0] < min)
		{
			min = stack[i][0];
			min_index = i;
		}
	return (min_index);
}

void	push_min(int **stack_a, int **stack_b, int len)
{
	int	min_index;

	min_index = find_min(stack_a);
	if (min_index == 1)
		op_ra(stack_a, len);
	if (min_index == 2 && len == 5)
	{
		op_ra(stack_a, len);
		op_ra(stack_a, len);
	}
	if ((min_index == 2 && len == 4) || (min_index == 3 && len == 5))
	{
		op_rra(stack_a, len);
		op_rra(stack_a, len);
	}
	if ((min_index == 3 && len == 4) || min_index == 4)
		op_rra(stack_a, len);
	op_pb(stack_a, stack_b);
}

void	four_stack(int **stack_a, int **stack_b)
{
	push_min(stack_a, stack_b, 4);
	three_stack(stack_a);
	op_pa(stack_a, stack_b);
}

void	five_stack(int **stack_a, int **stack_b)
{
	push_min(stack_a, stack_b, 5);
	four_stack(stack_a, stack_b);
	op_pa(stack_a, stack_b);
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
	//else
		//radix_sort(stack_a, stack_b);
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
