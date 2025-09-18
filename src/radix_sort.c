/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:08:42 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/12 11:19:16 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <limits.h>

int	check_bits_sorted(t_index_arr *stack, int bits)
{
	int				i;
	unsigned int	bit_state;

	i = 0;
	bit_state = 0;
	while (i < stack->len)
	{
		if (((stack->index[i] >> bits) & 1) > bit_state)
			bit_state = 1;
		if (((stack->index[i] >> bits) & 1) < bit_state)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	bitsort(t_index_arr *a, t_index_arr *b, int bits)
{
	int	i;
	int	len;

	i = 0;
	len = a->len;
	while (i < len)
	{
		if (((a->index[0] >> bits) & 1) == 1)
			index_op_ra(a);
		else
			index_op_pb(a, b);
		i++;
	}
	while (b->len != 0)
		index_op_pa(a, b);
}

int	ft_bitsize_int(int nbr)
{
	int	res;

	res = 1;
	while (nbr > 1)
	{
		nbr /= 2;
		res++;
	}
	return (res);
}

void	radix(t_index_arr *stack_a, t_index_arr *stack_b)
{
	int	bit_shift;
	int	index_bit_size;

	bit_shift = 0;
	index_bit_size = ft_bitsize_int(stack_a->len);
	while (bit_shift < index_bit_size)
	{
		if (check_bits_sorted(stack_a, bit_shift) == FALSE)
			bitsort(stack_a, stack_b, bit_shift);
		bit_shift++;
	}
}

void	copy_values(t_int_arr *output, t_index_arr *input)
{
	int	i;

	i = 0;
	while (i < input->len)
	{
		output->arr[i] = input->arr[i];
		i++;
	}
}

void	print_stack(t_index_arr *stack)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		ft_printf("Value %d Index %d\n", stack->arr[i], stack->index[i]);
		i++;
	}
	ft_printf("Len is: %d\n", stack->len);
}
