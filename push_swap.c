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

/*
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
*/



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

void	free_and_exit(int **stack, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(stack[i]);
		i++;
	}
}

int	**build_stack(char **array)
{
	int	**stack;
	int	i;
	int	len;

	len = ft_arraylen(array);
	stack = malloc((len + 1) * sizeof(int *));
	if (!stack)
		return (NULL);
	i = 0;
	while (array[i])
	{
		stack[i] = malloc(2 * sizeof(int));
		if (!stack[i])
		{
			free_and_exit(stack, i);
			return (NULL);
		}
		stack[i][0] = ft_atoi(array[i]);
		i++;
	}
	stack[len] = NULL;
	return (stack);
}

void	print_stack(int	**stack)
{
	int i;

	i = 0;
	while (stack[i])
	{
		ft_printf("Data is: %d\n", stack[i][0]);
		i++;
	}
}

void	check_build_sort(char **array)
{
	int	**stack;

	if (ft_arrcheck(array, ft_isnum) == -1 || check_dup(array) == -1)
		return ;
	stack = build_stack(array);
	if (!stack)
		return ;
	print_stack(stack);
	// TODO make the build index function
	build_index(stack);
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
