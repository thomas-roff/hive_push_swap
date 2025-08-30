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

#include "push_swap.h"

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
	while (stack[++i] && stack[i][1] != ARR_NT)
	{
		if (stack[i][0] < min)
		{
			min = stack[i][0];
			min_index = i;
		}
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
