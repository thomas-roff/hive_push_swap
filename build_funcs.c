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

#include "push_swap.h"

int	**build_stack(char **array, int len)
{
	int			**stack;
	long long	temp;
	int			i;

	stack = malloc((len + 1) * sizeof(int *));
	if (!stack)
		return (NULL);
	i = 0;
	while (array[i])
	{
		stack[i] = malloc(2 * sizeof(int));
		temp = ft_super_atoi(array[i]);
		if (!stack[i] || temp > INT32_MAX || temp < INT32_MIN)
		{
			error_free_and_exit(stack, i + 1);
			free(stack);
			return (NULL);
		}
		stack[i][0] = (int)temp;
		stack[i][1] = 0;
		i++;
	}
	stack[len] = NULL;
	return (stack);
}

int	**build_empty_stack(int len)
{
	int			**stack;
	int			i;

	stack = malloc((len + 1) * sizeof(unsigned int *));
	if (!stack)
		return (NULL);
	i = 0;
	while (i < len)
	{
		stack[i] = malloc(2 * sizeof(unsigned int));
		if (!stack[i])
		{
			error_free_and_exit(stack, i + 1);
			free(stack);
			return (NULL);
		}
		stack[i][0] = 0;
		stack[i][1] = 2;
		i++;
	}
	stack[len] = NULL;
	return (stack);
}

unsigned int	**build_uin_stack(int **stack, int len)
{
	unsigned int	**uin_stack;
	int				i;

	uin_stack = malloc((len + 1) * sizeof(int *));
	if (!uin_stack)
		return (NULL);
	i = 0;
	while (i < len)
	{
		uin_stack[i] = malloc(2 * sizeof(int));
		if (stack)
		{
			uin_stack[i][0] = (unsigned int)(stack[i][0] ^ 0x80000000);
			uin_stack[i][1] = 0;
		}
		else
		{
			uin_stack[i][0] = (unsigned int)(0 ^ 0x80000000);
			uin_stack[i][1] = 2;
		}
		i++;
	}
	uin_stack[len] = NULL;
	return (uin_stack);
}

void	free_and_exit_uin(unsigned int **stack_a, unsigned int **stack_b)
{
	int	i;

	i = 0;
	if (stack_a)
	{
		while (stack_a[i])
		{
			free(stack_a[i]);
			i++;
		}
		free(stack_a);
	}
	i = 0;
	if (stack_b)
	{
		while (stack_b[i])
		{
			free(stack_b[i]);
			i++;
		}
		free(stack_b);
	}
}
