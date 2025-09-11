/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:13:52 by thblack-          #+#    #+#             */
/*   Updated: 2025/08/27 15:20:55 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_issorted(t_int_arr *stack)
{
	int	i;

	i = 0;
	while (i < stack->len - 1)
	{
		if (stack->arr[i] > stack->arr[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	free_exit(t_int_arr *stack_a, t_int_arr *stack_b, int check)
{
	if (stack_a)
	{
		free(stack_a->arr);
		free(stack_a);
	}
	if (stack_b)
	{
		free(stack_b->arr);
		free(stack_b);
	}
	return (check);
}

void	error_free_exit(t_int_arr *stack)
{
	free(stack->arr);
	free(stack);
}
