/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:03:50 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/12 11:31:31 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
	if (ft_arrcheck(array, ft_isnum) == FALSE || len < 1
		|| check_dup_strings(array) == KO || check_valid_numbers(array) == KO)
		return (KO);
	if (len == 1)
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

char	**string_input(char *str)
{
	char		**array;

	if (!str)
		return (NULL);
	array = ft_split(str, ' ');
	if (!array)
		return (NULL);
	return (array);
}

int	main(int argc, char *argv[])
{
	char	**array;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		array = string_input(argv[1]);
		if (!array)
			ft_putendl_fd("Error", 2);
		if (!check_build_sort(array))
			ft_putendl_fd("Error", 2);
		free_array(array);
		free(array);
	}
	if (argc > 2)
		if (!check_build_sort(&argv[1]))
			ft_putendl_fd("Error", 2);
	return (0);
}
