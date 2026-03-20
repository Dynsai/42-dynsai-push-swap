/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parenas- <parenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:46:25 by parenas-          #+#    #+#             */
/*   Updated: 2026/03/20 13:21:59 by parenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(void);
int		ft_strlen(const char *s);
//BORRAR ESTA FUNCION
void	print_stack(t_stack *stack);

void	ft_error(void)
{
	write (1, "Error", 5);
	write (1, "\n", 1);
	exit (1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

//BORRAR ESTA FUNCION DE TESTING
void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}
