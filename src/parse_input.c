/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parenas- <parenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:54:28 by parenas-          #+#    #+#             */
/*   Updated: 2026/03/19 15:58:33 by parenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*parse_input(int argc, char **argv);
static void	parse_string(char *argv, t_stack **stack);

t_stack	*parse_input(int argc, char **argv)
{
	int	i;
	t_stack *stack;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		parse_string(argv[i], &stack);
		i++;
	}
	return (stack);
}

static void	parse_string(char *argv, t_stack **stack)
{
	char	**numbers;
	t_stack *node;
	int		i;
	long	num;

	i = 0;
	num = 0;
	numbers = ft_split(argv, ' ');
	if (!numbers)
		ft_error();
	while (numbers[i])
	{
		if (!is_valid_number(numbers[i], &num))
		{
			while (numbers[i])
				free(numbers[i++]);
			free(numbers);
			free_stack(*stack);
			ft_error();
		}
		node = ft_lstnew((int)num);
		ft_lstadd_back(stack, node);
		free(numbers[i++]);
	}
	free(numbers);
}
