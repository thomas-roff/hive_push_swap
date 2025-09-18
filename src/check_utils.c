/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:49:57 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/18 12:58:05 by thblack-         ###   ########.fr       */
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

int	ft_isarr(char **array, int (f)(int))
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

int	ft_strisnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	arraycheck(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (!ft_strisnum(array[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
