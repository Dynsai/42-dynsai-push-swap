/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parenas- <parenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:23:18 by parenas-          #+#    #+#             */
/*   Updated: 2026/03/19 14:12:06 by parenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdlib.h>
# include <unistd.h>

//utils
long	ft_atol(const char *nptr);
char	**ft_split(char const *s, char c);
void	ft_error();
int		ft_strlen(const char *s);
int		is_valid_number(char *s);

//Lists
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

t_stack	*ft_lstnew(int content);
void	ft_lstadd_front(t_stack **lst, t_stack *node);
void	ft_lstadd_back(t_stack **lst, t_stack *node);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	free_stack(t_stack *lst);
void	print_stack(t_stack *stack);

//Parsing
t_stack	*parse_input(int argc, char **argv);
int		check_duplicates(t_stack *stack);

#endif