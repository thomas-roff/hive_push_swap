/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:21:46 by thblack-          #+#    #+#             */
/*   Updated: 2025/08/25 18:22:33 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	op_sa(t_int_arr *stack)
{
	int	temp;

	temp = stack->arr[0];
	stack->arr[0] = stack->arr[1];
	stack->arr[1] = temp;
	write(1, "sa\n", 3);
}

void	op_ra(t_int_arr *stack)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack->arr[0];
	while (++i < stack->len)
		stack->arr[i - 1] = stack->arr[i];
	stack->arr[stack->len - 1] = temp;
	write(1, "ra\n", 3);
}

void	op_rra(t_int_arr *stack)
{
	int	len;
	int	temp;

	len = stack->len;
	temp = stack->arr[len - 1];
	while (len-- > 1)
		stack->arr[len] = stack->arr[len - 1];
	stack->arr[0] = temp;
	write(1, "rra\n", 4);
}

void	op_pa(t_int_arr *stack_a, t_int_arr *stack_b)
{
	int	i;

	i = stack_a->len;
	while (i-- > 0)
		stack_a->arr[i + 1] = stack_a->arr[i];
	stack_a->arr[0] = stack_b->arr[0];
	i = 0;
	while (++i < stack_b->len)
		stack_b->arr[i - 1] = stack_b->arr[i];
	stack_b->arr[i - 1] = 0;
	stack_a->len++;
	stack_b->len--;
	write(1, "pa\n", 3);
}

void	op_pb(t_int_arr *stack_a, t_int_arr *stack_b)
{
	int	i;

	i = stack_b->len;
	while (i-- > 0)
		stack_b->arr[i + 1] = stack_b->arr[i];
	stack_b->arr[0] = stack_a->arr[0];
	i = 0;
	while (++i < stack_a->len)
		stack_a->arr[i - 1] = stack_a->arr[i];
	stack_a->arr[i - 1] = 0;
	stack_b->len++;
	stack_a->len--;
	write(1, "pb\n", 3);
}
