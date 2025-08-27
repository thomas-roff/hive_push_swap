/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:08:42 by thblack-          #+#    #+#             */
/*   Updated: 2025/08/27 15:32:17 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_bit_sorted(unsigned int **stack, int bits)
{
	int				i;
	unsigned int	value;

	i = 0;
	value = 0;
	while (stack[i] && stack[i][1] != 2)
	{
		if (((stack[i][0] >> bits) & 1) > value)
			value = 1;
		if (((stack[i][0] >> bits) & 1) < value)
			return (0);
		i++;
	}
	return (1);
}

void	radix(unsigned int **stack_a, unsigned int **stack_b, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < 32)
	{
		if (check_bit_sorted(stack_a, i) == 1)
			i++;
		else
		{
			j = 0;
			while (j < len)
			{
				stack_a[0][1] = ((stack_a[0][0] >> i) & 1);
				if (stack_a[0][1] == 1)
					uin_op_ra(stack_a, ft_uinstacklen(stack_a));
				else
					uin_op_pb(stack_a, stack_b);
				j++;
			}
			while (ft_uinstacklen(stack_b) != 0)
				uin_op_pa(stack_a, stack_b);
			i++;
		}
	}
}

void	convert_to_signed(int **output, unsigned int **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		output[i][0] = (int)(input[i][0] ^ 0x80000000);
		i++;
	}
}

void	large_stack(int **stack, int len)
{
	unsigned int	**uin_stack_a;
	unsigned int	**uin_stack_b;

	uin_stack_a = build_uin_stack(stack, len);
	if (!uin_stack_a)
		return ;
	uin_stack_b = build_uin_stack(NULL, len);
	if (!uin_stack_b)
		return (free_exit_uin(uin_stack_a, NULL));
	radix(uin_stack_a, uin_stack_b, len);
	convert_to_signed(stack, uin_stack_a);
	free_exit_uin(uin_stack_a, uin_stack_b);
}
