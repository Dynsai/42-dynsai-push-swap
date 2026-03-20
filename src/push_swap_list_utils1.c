/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_utils1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parenas- <parenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:09:56 by parenas-          #+#    #+#             */
/*   Updated: 2026/03/20 13:21:17 by parenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *node);
void	ft_lstadd_front(t_stack **lst, t_stack *node);
t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);

/*
add the node ’node’ to the end of the stack ’lst’.
*/
void	ft_lstadd_back(t_stack **lst, t_stack *node)
{
	t_stack	*last;

	if (!lst || !node)
		return ;
	if (*lst == NULL)
		*lst = node;
	else
	{
		last = ft_lstlast(*lst);
		last->next = node;
	}
}

/*
add the node 'node' to the start of the stack ’lst’.
*/
void	ft_lstadd_front(t_stack **lst, t_stack *node)
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
t_stack	*ft_lstnew(int content)
{
	t_stack	*elem;

	elem = malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->value = content;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

/*
return the last node of the stack.
*/
t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

/*
count the number of nodes in a stack
*/
int	ft_lstsize(t_stack *lst)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
