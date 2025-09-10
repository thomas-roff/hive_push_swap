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

#include "../inc/push_swap.h"

int	check_bits_sorted(t_uint_arr *stack, int bits)
{
	int				i;
	unsigned int	bit_state;

	i = 0;
	bit_state = 0;
	while (i < stack->len)
	{
		if (((stack->arr[i] >> bits) & 1) > bit_state)
			bit_state = 1;
		if (((stack->arr[i] >> bits) & 1) < bit_state)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	bitsort(t_uint_arr *a, t_uint_arr *b, int bits)
{
	int	i;
	int	len;

	i = 0;
	len = a->len;
	while (i < len)
	{
		if (((a->arr[0] >> bits) & 1) == 1)
			uin_op_ra(a);
		else
			uin_op_pb(a, b);
		i++;
	}
	while (b->len != 0)
		uin_op_pa(a, b);
}

void	radix(t_uint_arr *stack_a, t_uint_arr *stack_b)
{
	int	bit_shift;
	int	int_bit_length;

	bit_shift = 0;
	int_bit_length = ((int) sizeof(int) * CHAR_BIT);
	while (bit_shift < int_bit_length)
	{
		if (check_bits_sorted(stack_a, bit_shift) == FALSE)
			bitsort(stack_a, stack_b, bit_shift);
		bit_shift++;
	}
}

void	convert_to_signed(t_int_arr *output, t_uint_arr *input)
{
	int	i;

	i = 0;
	while (i < input->len)
	{
		output->arr[i] = (int)(input->arr[i] ^ INT_MIN);
		i++;
	}
}

void	large_stack(t_int_arr *stack)
{
	t_uint_arr	*uin_stack_a;
	t_uint_arr	*uin_stack_b;

	uin_stack_a = build_uin_stack(stack);
	if (!uin_stack_a)
		return ;
	uin_stack_b = build_empty_uin_stack(stack->len);
	if (!uin_stack_b)
		return (free_exit_uin(uin_stack_a, NULL));
	radix(uin_stack_a, uin_stack_b);
	convert_to_signed(stack, uin_stack_a);
	free_exit_uin(uin_stack_a, uin_stack_b);
}
