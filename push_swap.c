/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:03:50 by thblack-          #+#    #+#             */
/*   Updated: 2025/08/13 14:37:21 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

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

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

int	check_dup(char **array)
{
	int i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 1;
		while (array[i + j])
		{
			if (ft_strcmp(array[i], array[i + j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
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
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

t_dbllist	*build_list(char **array)
{
	t_dbllist	*lst;
	int			i;

	lst = ft_dbllstnew(array[0]);
	lst->index = 0;
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

void	check_build_sort(char **array)
{
	t_dbllist	*list;

	if (ft_arrcheck(array, ft_isnum) == -1 || check_dup(array) == -1)
		return ;
	list = build_list(array);
	if (!list)
		return ;
	
	//push_swap(list);
}

char	**string_input(char *str)
{
	char		**array;

	if (!str)
		return (NULL);
	array = ft_split(str, ' ');
	if (!array)
	{
		ft_printf("ft_split error");
		return (NULL);
	}
	return (array);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	if (argc == 2)
		check_build_sort(string_input(argv[1]));
	if (argc > 2)
		check_build_sort(&argv[1]);
	return (0);
}
