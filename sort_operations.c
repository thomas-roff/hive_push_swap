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

#include "push_swap.h"

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
	stack_b[len_b - 1][1] = 2;
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
	stack_a[len_a - 1][1] = 2;
	write(1, "pb\n", 3);
}
