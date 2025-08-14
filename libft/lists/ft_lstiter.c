/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:05:19 by thblack-          #+#    #+#             */
/*   Updated: 2025/05/05 16:08:47 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return (-1);
	while (lst)
	{
		f(lst->data);
		lst = lst->next;
	}
	return (1);
}
