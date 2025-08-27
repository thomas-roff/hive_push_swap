/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:13:52 by thblack-          #+#    #+#             */
/*   Updated: 2025/08/27 15:20:55 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacklen(int **stack)
{
	int	len;
	int	i;

	if (!stack || !*stack)
		return (0);
	len = 0;
	while (stack[len])
		len++;
	i = 0;
	while (stack[i])
	{
		if (stack[i][1] == 2 && i < len)
			return (i);
		i++;
	}
	return (len);
}

int	ft_issorted(int **stack)
{
	int	i;

	i = 0;
	while (stack[i] && stack[i + 1])
	{
		if (stack[i][0] > stack[i + 1][0])
			return (-1);
		i++;
	}
	return (1);
}

void	free_and_exit(int **stack_a, int **stack_b)
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

void	error_free_and_exit(int **stack, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(stack[i]);
		i++;
	}
}

int	ft_uinstacklen(unsigned int **stack)
{
	int	len;
	int	i;

	if (!stack || !*stack)
		return (0);
	len = 0;
	while (stack[len])
		len++;
	i = 0;
	while (stack[i])
	{
		if (stack[i][1] == 2 && i < len)
			return (i);
		i++;
	}
	return (len);
}
