/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbllstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:56:19 by thblack-          #+#    #+#             */
/*   Updated: 2025/08/11 10:02:56 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_dbllist	*ft_dbllstnew(void *content)
{
	t_dbllist	*lst;

	lst = (t_dbllist *)malloc(sizeof(t_dbllist));
	if (!lst)
		return (NULL);
	else
	{
		lst->content = content;
		lst->index = 0;
	}
	lst->prev = NULL;
	lst->next = NULL;
	return (lst);
}
