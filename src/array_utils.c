/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:11:08 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/18 13:35:14 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_arraylen(char **array)
{
	int	len;

	if (!array)
		return (-1);
	if (!*array)
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
