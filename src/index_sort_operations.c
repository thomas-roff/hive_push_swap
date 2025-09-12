/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_sort_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:21:46 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/12 11:37:55 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	assign_index(t_index_arr *stack, int min_index)
{
	int	i;
	int	index;
	int	min;
	int	temp;

	min = stack->arr[min_index];
	stack->arr[min_index] = min;
	stack->index[min_index] = 0;
	index = 1;
	while (index < stack->len)
	{
		i = 0;
		temp = INT_MAX;
		while (i < stack->len)
		{
			if (stack->arr[i] > min && stack->arr[i] < temp)
			{
				temp = stack->arr[i];
				min_index = i;
			}
			i++;
		}
		stack->index[min_index] = index++;
		min = temp;
	}
}

void	index_op_ra(t_index_arr *stack)
{
	int				i;
	int				n_temp;
	unsigned int	i_temp;

	i = 0;
	n_temp = stack->arr[0];
	i_temp = stack->index[0];
	while (++i < stack->len)
	{
		stack->arr[i - 1] = stack->arr[i];
		stack->index[i - 1] = stack->index[i];
	}
	stack->arr[stack->len - 1] = n_temp;
	stack->index[stack->len - 1] = i_temp;
	write(1, "ra\n", 3);
}

void	index_op_pa(t_index_arr *stack_a, t_index_arr *stack_b)
{
	int	i;

	i = stack_a->len;
	while (i-- > 0)
	{
		stack_a->arr[i + 1] = stack_a->arr[i];
		stack_a->index[i + 1] = stack_a->index[i];
	}
	stack_a->arr[0] = stack_b->arr[0];
	stack_a->index[0] = stack_b->index[0];
	i = 0;
	while (++i < stack_b->len)
	{
		stack_b->arr[i - 1] = stack_b->arr[i];
		stack_b->index[i - 1] = stack_b->index[i];
	}
	stack_b->arr[i - 1] = 0;
	stack_b->index[i - 1] = 0;
	stack_a->len++;
	stack_b->len--;
	write(1, "pa\n", 3);
}

void	index_op_pb(t_index_arr *stack_a, t_index_arr *stack_b)
{
	int	i;

	i = stack_b->len;
	while (i-- > 0)
	{
		stack_b->arr[i + 1] = stack_b->arr[i];
		stack_b->index[i + 1] = stack_b->index[i];
	}
	stack_b->arr[0] = stack_a->arr[0];
	stack_b->index[0] = stack_a->index[0];
	i = 0;
	while (++i < stack_a->len)
	{
		stack_a->arr[i - 1] = stack_a->arr[i];
		stack_a->index[i - 1] = stack_a->index[i];
	}
	stack_a->arr[i - 1] = 0;
	stack_a->index[i - 1] = 0;
	stack_b->len++;
	stack_a->len--;
	write(1, "pb\n", 3);
}
