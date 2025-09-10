/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:19:46 by thblack-          #+#    #+#             */
/*   Updated: 2025/08/25 20:26:01 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

t_uint_arr	*build_uin_stack(t_int_arr *stack)
{
	t_uint_arr	*uin_stack;
	int			i;

	uin_stack = (t_uint_arr *)malloc(sizeof(t_uint_arr));
	if (!uin_stack)
		return (NULL);
	uin_stack->arr = (unsigned int *)malloc(stack->len * sizeof(unsigned int));
	if (!uin_stack->arr)
	{
		free(uin_stack);
		return (NULL);
	}
	i = 0;
	while (i < stack->len)
	{
		uin_stack->arr[i] = (unsigned int)(stack->arr[i] ^ INT_MIN);
		i++;
	}
	uin_stack->len = stack->len;
	return (uin_stack);
}

t_uint_arr	*build_empty_uin_stack(int len)
{
	t_uint_arr	*uin_stack;
	int			i;

	uin_stack = (t_uint_arr *)malloc(sizeof(t_uint_arr));
	if (!uin_stack)
		return (NULL);
	uin_stack->arr = (unsigned int *)malloc(len * sizeof(unsigned int));
	if (!uin_stack->arr)
	{
		free(uin_stack);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		uin_stack->arr[0] = 0;
		i++;
	}
	uin_stack->len = 0;
	return (uin_stack);
}

void	free_exit_uin(t_uint_arr *stack_a, t_uint_arr *stack_b)
{
	if (stack_a)
	{
		free(stack_a->arr);
		free(stack_a);
	}
	if (stack_b)
	{
		free(stack_b->arr);
		free(stack_b);
	}
}
