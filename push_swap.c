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

#include "libft/libft.h"
#include "push_swap.h"
#include <stdint.h>

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

int	check_build_sort(char **array)
{
	int	**stack_a;
	int	**stack_b;
	int	len;

	len = ft_arraylen(array);
	if (ft_arrcheck(array, ft_isnum) == -1 || check_dup(array) == -1
		|| len == 1)
		return (0);
	stack_a = build_stack(array, len);
	stack_b = NULL;
	if (!stack_a)
		return (0);
	if (ft_issorted(stack_a) == 1)
		return (free_and_exit(stack_a, NULL, 1));
	if (len <= 5)
	{
		stack_b = build_empty_stack(len);
		if (!stack_b)
			return (free_and_exit(stack_a, NULL, 0));
		small_stack(stack_a, stack_b, len);
	}
	else
		large_stack(stack_a, len);
	return (free_and_exit(stack_a, stack_b, 1));
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
			ft_printf("Error\n");
		if (!check_build_sort(array))
			ft_printf("Error\n");
		free_array(array);
		free(array);
	}
	if (argc > 2)
		if (!check_build_sort(&argv[1]))
			ft_printf("Error\n");
	return (0);
}
