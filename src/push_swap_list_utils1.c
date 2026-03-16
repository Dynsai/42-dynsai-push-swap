/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_utils1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parenas- <parenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:09:56 by parenas-          #+#    #+#             */
/*   Updated: 2026/03/16 22:28:09 by parenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *node);
void	ft_lstadd_front(t_list **lst, t_list *node);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
int	ft_lstsize(t_list *lst);

/*
add the node ’node’ to the end of the list ’lst’.
*/
void	ft_lstadd_back(t_list **lst, t_list *node)
{
	t_list	*last;

	if (!lst || !node)
		return ;
	if (*lst == NULL)
	{
		*lst = node;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = node;
	}
}

/*
add the node 'node' to the start of the list ’lst’.
*/
void	ft_lstadd_front(t_list **lst, t_list *node)
{
	node->next = *lst;
	*lst = node;
}

/*
Create a new node using malloc(3). The
member variable ‘content’ is initialized with the
content of the ‘content’ parameter. The variable
‘next’ is initialized with NULL.
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

/*
return the last node of the list.
*/
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

/*
count the number of nodes in a list
*/
int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
