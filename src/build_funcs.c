/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:19:46 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/12 11:32:59 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <limits.h>

t_int_arr	*build_stack(char **array, int len)
{
	t_int_arr	*stack;
	long long	temp;
	int			i;

	stack = (t_int_arr *)malloc(sizeof(t_int_arr));
	if (!stack)
		return (NULL);
	stack->arr = (int *)malloc(len * sizeof(int));
	i = 0;
	while (array[i])
	{
		temp = ft_super_atoi(array[i]);
		if (temp > INT_MAX || temp < INT_MIN || !stack->arr)
		{
			free(stack->arr);
			free(stack);
			return (NULL);
		}
		stack->arr[i] = (int)temp;
		i++;
	}
	stack->len = len;
	return (stack);
}

t_int_arr	*build_empty_stack(int len)
{
	t_int_arr	*stack;
	int			i;

	stack = (t_int_arr *)malloc(sizeof(t_int_arr));
	if (!stack)
		return (NULL);
	stack->arr = (int *)malloc(len * sizeof(int));
	if (!stack->arr)
	{
		free(stack);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		stack->arr[0] = 0;
		i++;
	}
	stack->len = 0;
	return (stack);
}

void	copy_to_index_stack(t_index_arr *output, t_int_arr *input)
{
	int	i;

	i = 0;
	while (i < input->len)
	{
		output->arr[i] = input->arr[i];
		output->index[i] = 0;
		i++;
	}
	output->len = input->len;
}

t_index_arr	*build_index_stack(t_int_arr *stack)
{
	t_index_arr	*index_stack;

	index_stack = (t_index_arr *)malloc(sizeof(t_index_arr));
	if (!index_stack)
		return (NULL);
	index_stack->arr = malloc(stack->len * sizeof(int));
	index_stack->index = malloc(stack->len * sizeof(unsigned int));
	if (!index_stack->arr || !index_stack->index)
	{
		free_exit_index(index_stack);
		free(index_stack);
		return (NULL);
	}
	copy_to_index_stack(index_stack, stack);
	assign_index(index_stack, find_min(stack));
	index_stack->len = stack->len;
	return (index_stack);
}

t_index_arr	*build_empty_index_stack(int len)
{
	t_index_arr	*index_stack;
	int			i;

	index_stack = (t_index_arr *)malloc(sizeof(t_index_arr));
	if (!index_stack)
		return (NULL);
	index_stack->arr = malloc(len * sizeof(int));
	index_stack->index = malloc(len * sizeof(unsigned int));
	if (!index_stack->arr || !index_stack->index)
	{
		free_exit_index(index_stack);
		free(index_stack);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		index_stack->arr[0] = 0;
		index_stack->index[0] = 0;
		i++;
	}
	index_stack->len = 0;
	return (index_stack);
}
