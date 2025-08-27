/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uin_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:28:50 by thblack-          #+#    #+#             */
/*   Updated: 2025/08/25 20:30:33 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	print_uin_stack(unsigned int **stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		ft_printf("Data is: %d %d\n", (int)(stack[i][0] ^ 0x80000000), stack[i][1]);
		i++;
	}
}
