/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbllists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:58:03 by thblack-          #+#    #+#             */
/*   Updated: 2025/08/20 09:58:46 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

t_dbllist	*ft_dbllstnew(void *data)
{
	t_dbllist	*lst;

	lst = (t_dbllist *)malloc(sizeof(t_dbllist));
	if (!lst)
		return (NULL);
	else
	{
		lst->data = data;
		lst->len = 1;
	}
	lst->prev = lst;
	lst->next = lst;
	return (lst);
}

int	ft_dbllstadd_back(t_dbllist **lst, t_dbllist *new)
{
	t_dbllist	*temp;

	if (!new)
		return (-1);
	if (!*lst)
	{
		*lst = new;
		return (1);
	}
	temp = (*lst)->prev;
	temp->next = new;
	new->next = *lst;
	new->prev = (*lst)->prev;
	(*lst)->prev = new;
	(*lst)->len += 1;
	return (1);
}

int	ft_dbllstadd_front(t_dbllist **lst, t_dbllist *new)
{
	if (!new)
		return (-1);
	if (!*lst)
	{
		*lst = new;
		return (1);
	}
	ft_dbllstadd_back(lst, new);
	*lst = new;
	return (1);
}

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

t_dbllist	*build_list(char **array)
{
	t_dbllist	*lst;
	int			i;

	lst = ft_dbllstnew(array[0]);
	if (!lst)
		return (NULL);
	i = 1;
	while (array[i])
	{
		if (!ft_dbllstadd_back(&lst, ft_dbllstnew(array[i])))
			return (NULL);
		i++;
	}
	return (lst);
}

int	ft_printdbllist(t_dbllist *lst)
{
	t_dbllist	*temp;
	int			i;

	if (!lst)
		return (-1);
	temp = lst;
	i = lst->len;
	ft_printf("Length is: %d\n", i);
	while (i > 0)
	{
		if(!ft_printf("Data is: %s\n", temp->data))
			return (-1);
		temp = temp->next;
		i--;
	}
	return (1);
}
