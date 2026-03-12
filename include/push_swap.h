/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parenas- <parenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:23:18 by parenas-          #+#    #+#             */
/*   Updated: 2026/03/09 14:50:35 by parenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdlib.h>
# include <unistd.h>

//main functions of libft

int		ft_atol(const char *nptr);
char	**ft_split(char const *s, char c);
void	integer_checker(long l);


//Lists

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *node);
void	ft_lstadd_back(t_list **lst, t_list *node);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

#endif