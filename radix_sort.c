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

int	check_bits_sorted(unsigned int **stack, int bits)
{
	int				i;
	unsigned int	bit_state;

	i = 0;
	bit_state = 0;
	while (stack[i] && stack[i][1] != 2)
	{
		if (((stack[i][0] >> bits) & 1) > bit_state)
			bit_state = 1;
		if (((stack[i][0] >> bits) & 1) < bit_state)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	bitsort(unsigned int **a, unsigned int **b, int len, int bits)
{
	int	i;

	i = 0;
	while (i < len)
	{
		a[0][1] = ((a[0][0] >> bits) & 1);
		if (a[0][1] == 1)
			uin_op_ra(a, ft_uinstacklen(a));
		else
			uin_op_pb(a, b);
		i++;
	}
	while (ft_uinstacklen(b) != 0)
		uin_op_pa(a, b);
}

void	radix(unsigned int **stack_a, unsigned int **stack_b, int len)
{
	int	bit_shift;
	int	int_bit_length;

	bit_shift = 0;
	int_bit_length = ((int) sizeof(int) * CHAR_BIT);
	while (bit_shift < int_bit_length)
	{
		if (check_bits_sorted(stack_a, bit_shift) == FALSE)
			bitsort(stack_a, stack_b, len, bit_shift);
		bit_shift++;
	}
}

void	convert_to_signed(int **output, unsigned int **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		output[i][0] = (int)(input[i][0] ^ INT_MIN);
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
