/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:03:50 by thblack-          #+#    #+#             */
/*   Updated: 2025/08/27 15:43:06 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	small_stack(t_int_arr *stack_a, t_int_arr *stack_b)
{
	if (stack_a->len == 2)
		op_sa(stack_a);
	if (stack_a->len == 3)
		three_stack(stack_a);
	if (stack_a->len == 4)
		four_stack(stack_a, stack_b);
	if (stack_a->len == 5)
		five_stack(stack_a, stack_b);
}

int	check_build_sort(char **array)
{
	t_int_arr	*stack_a;
	t_int_arr	*stack_b;
	int			len;

	len = ft_arraylen(array);
	if (ft_arrcheck(array, ft_isnum) == FALSE || check_no_dup(array) == FALSE
		|| len == 1)
		return (0);
	stack_a = build_stack(array, len);
	stack_b = NULL;
	if (!stack_a)
		return (0);
	if (ft_issorted(stack_a) == TRUE)
		return (free_exit(stack_a, NULL, OK));
	if (stack_a->len <= 5)
	{
		stack_b = build_empty_stack(stack_a->len);
		if (!stack_b)
			return (free_exit(stack_a, NULL, KO));
		small_stack(stack_a, stack_b);
	}
	else
		large_stack(stack_a);
	return (free_exit(stack_a, stack_b, OK));
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
