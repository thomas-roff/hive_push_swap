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

#include "../inc/push_swap.h"

int	ft_issorted(t_int_arr *stack)
{
	int	i;

	i = 0;
	while (i < stack->len - 1)
	{
		if (stack->arr[i] > stack->arr[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	free_exit(t_int_arr *stack_a, t_int_arr *stack_b, int check)
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
	return (check);
}

void	error_free_exit(t_int_arr *stack)
{
	free(stack->arr);
	free(stack);
}

long long	ft_super_atoi(const char *nptr)
{
	long long	res;
	int			pn;
	int			digit;

	res = 0;
	pn = 1;
	while (ft_isspace((int)*nptr) == 1)
		nptr++;
	if (*nptr == '-')
	{
		pn = pn * -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (ft_isdigit((int)*nptr) == 1)
	{
		digit = *nptr - '0';
		res = res * 10 + digit;
		nptr++;
	}
	return (res * pn);
}

int	check_dup_int(t_int_arr *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->len - 1)
	{
		j = 1;
		while (i + j < stack->len)
		{
			if (stack->arr[i + j] == stack->arr[i])
				return (KO);
			j++;
		}
		i++;
	}
	return (OK);
}
