/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:11:08 by thblack-          #+#    #+#             */
/*   Updated: 2025/08/27 15:23:05 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_dup_strings(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 1;
		while (array[i + j])
		{
			if (ft_strcmp(array[i], array[i + j]) == 0)
				return (KO);
			j++;
		}
		i++;
	}
	return (OK);
}

int	check_valid_numbers(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (ft_isspace(array[i][j]))
			j++;
		while (array[i][j] == '+' || array[i][j] == '-')
			j++;
		while (ft_isdigit(array[i][j]))
			j++;
		if (array[i][j])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	ft_arrcheck(char **array, int (f)(int))
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (!f(array[i][j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	ft_arraylen(char **array)
{
	int	len;

	if (!array || !*array)
		return (0);
	len = 0;
	while (array[len])
		len++;
	return (len);
}

void	free_array(char **array)
{
	while (*array)
	{
		free(*array);
		array++;
	}
}
