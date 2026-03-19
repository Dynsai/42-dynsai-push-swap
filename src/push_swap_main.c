/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parenas- <parenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:23:26 by parenas-          #+#    #+#             */
/*   Updated: 2026/03/19 14:04:36 by parenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	//t_stack	*b;

	//b = NULL;
	if (argc < 2)
		return (0);
	if (argc >= 2)
		a = parse_input(argc, argv);
	else
		ft_error();
	
	print_stack(a);
	free_stack(a);
	return (0);
}
