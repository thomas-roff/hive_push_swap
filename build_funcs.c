/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:19:46 by thblack-          #+#    #+#             */
/*   Updated: 2025/08/25 18:20:27 by thblack-         ###   ########.fr       */
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
