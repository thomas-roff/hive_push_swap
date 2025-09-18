/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:03:50 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/18 13:32:28 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdlib.h>

void	large_stack(t_int_arr *stack)
{
	t_index_arr	*index_stack_a;
	t_index_arr	*index_stack_b;

	index_stack_a = build_index_stack(stack);
	if (!index_stack_a)
		return ;
	index_stack_b = build_empty_index_stack(stack->len);
	if (!index_stack_b)
		return (free_exit_index(index_stack_a));
	radix(index_stack_a, index_stack_b);
	copy_values(stack, index_stack_a);
	free_exit_index(index_stack_a);
	free_exit_index(index_stack_b);
}

int	small_stack(t_int_arr *stack_a)
{
	t_int_arr	*stack_b;

	stack_b = build_empty_stack(stack_a->len);
	if (!stack_b)
		return (KO);
	if (stack_a->len == 2)
		op_sa(stack_a);
	if (stack_a->len == 3)
		three_stack(stack_a);
	if (stack_a->len == 4)
		four_stack(stack_a, stack_b);
	if (stack_a->len == 5)
		five_stack(stack_a, stack_b);
	free_exit(NULL, stack_b, OK);
	return (OK);
}

int	check_build_sort(char **array)
{
	t_int_arr	*stack_a;
	int			len;

	len = ft_arraylen(array);
	if (ft_isarr(array, ft_isnum) == FALSE
		|| arraycheck(array) == FALSE || len < 0
		|| check_dup_strings(array) == KO || check_valid_numbers(array) == KO)
		return (KO);
	if (len == 1 || len == 0)
		return (OK);
	stack_a = build_stack(array, len);
	if (!stack_a)
		return (0);
	if (check_dup_int(stack_a) == KO)
		return (free_exit(stack_a, NULL, KO));
	if (ft_issorted(stack_a) == TRUE)
		return (free_exit(stack_a, NULL, OK));
	if (stack_a->len <= 5)
	{
		if (!small_stack(stack_a))
			return (free_exit(stack_a, NULL, KO));
	}
	else
		large_stack(stack_a);
	return (free_exit(stack_a, NULL, OK));
}

int	string_input(char *str)
{
	char	**array;
	int		error_flag;

	if (!str)
		return (KO);
	array = ft_split(str, ' ');
	if (!array)
		return (KO);
	error_flag = check_build_sort(array);
	free_array(array);
	free(array);
	if (!error_flag)
		return (KO);
	return (OK);
}

int	main(int argc, char *argv[])
{
	int		error_flag;

	if (argc == 1)
		return (0);
	if (argc == 2)
		error_flag = string_input(argv[1]);
	if (argc > 2)
		error_flag = check_build_sort(&argv[1]);
	if (!error_flag)
	{
		ft_putendl_fd("Error", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
