/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbllstadd_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:35:23 by thblack-          #+#    #+#             */
/*   Updated: 2025/08/13 14:37:29 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dbllstadd_back(t_dbllist **lst, t_dbllist *new)
{
	t_dbllist	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	list->
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
