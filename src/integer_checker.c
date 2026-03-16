/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parenas- <parenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:25:06 by parenas-          #+#    #+#             */
/*   Updated: 2026/03/09 14:54:07 by parenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	integer_checker(long l)
{
	if (!(l <= INT_MAX && l >= INT_MIN))
	{
		write(1, "Error: Uno de los valores es un long", 36);
		exit (1);
	}
}
