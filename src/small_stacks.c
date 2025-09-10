/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:27:43 by thblack-          #+#    #+#             */
/*   Updated: 2025/08/27 15:13:52 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	three_stack(t_int_arr *stack)
{
	if (stack->arr[0] < stack->arr[1] && stack->arr[0] < stack->arr[2]
		&& stack->arr[1] > stack->arr[2])
	{
		op_rra(stack);
		op_sa(stack);
	}
	if (stack->arr[0] > stack->arr[1] && stack->arr[0] < stack->arr[2]
		&& stack->arr[1] < stack->arr[2])
		op_sa(stack);
	if (stack->arr[0] < stack->arr[1] && stack->arr[0] > stack->arr[2]
		&& stack->arr[1] > stack->arr[2])
		op_rra(stack);
	if (stack->arr[0] > stack->arr[1] && stack->arr[0] > stack->arr[2]
		&& stack->arr[1] < stack->arr[2])
		op_ra(stack);
	if (stack->arr[0] > stack->arr[1] && stack->arr[0] > stack->arr[2]
		&& stack->arr[1] > stack->arr[2])
	{
		op_ra(stack);
		op_sa(stack);
	}
}

int	find_min(t_int_arr *stack)
{
	int	i;
	int	min;
	int	min_index;

	if (!stack)
		return (0);
	i = 0;
	min = stack->arr[0];
	min_index = 0;
	while (i < stack->len)
	{
		if (stack->arr[i] < min)
		{
			min = stack->arr[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void	push_min(t_int_arr *stack_a, t_int_arr *stack_b, int len)
{
	int	min_index;

	min_index = find_min(stack_a);
	if (min_index == 1)
		op_ra(stack_a);
	if (min_index == 2 && len == 5)
	{
		op_ra(stack_a);
		op_ra(stack_a);
	}
	if ((min_index == 2 && len == 4) || (min_index == 3 && len == 5))
	{
		op_rra(stack_a);
		op_rra(stack_a);
	}
	if ((min_index == 3 && len == 4) || min_index == 4)
		op_rra(stack_a);
	op_pb(stack_a, stack_b);
}

void	four_stack(t_int_arr *stack_a, t_int_arr *stack_b)
{
	push_min(stack_a, stack_b, 4);
	three_stack(stack_a);
	op_pa(stack_a, stack_b);
}

void	five_stack(t_int_arr *stack_a, t_int_arr *stack_b)
{
	push_min(stack_a, stack_b, 5);
	four_stack(stack_a, stack_b);
	op_pa(stack_a, stack_b);
}
