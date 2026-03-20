/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parenas- <parenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:42:35 by parenas-          #+#    #+#             */
/*   Updated: 2026/03/20 15:31:10 by parenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static long		ft_atol(const char *nptr);
int			is_valid_number(char *s, long *num);
static int	integer_checker(long l);
static int	ascii_number_checker(char *s);
int			is_duplicated(t_stack *stack);

static long	ft_atol(const char *nptr)
{
	int		i;
	int		sig;
	long	res;

	i = 0;
	sig = 1;
	res = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sig *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sig);
}

int	is_valid_number(char *s, long *num)
{
	if (!(ascii_number_checker(s)))
		return (0);
	*num = ft_atol(s);
	if (!(integer_checker(*num)))
		return (0);
	return (1);
}

static int	ascii_number_checker(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static int	integer_checker(long l)
{
	if (!(l <= INT_MAX && l >= INT_MIN))
		return (0);
	else
		return (1);
}

int	is_duplicated(t_stack	*stack)
{
	t_stack	*i;
	t_stack	*j;

	i = stack;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (j->value == i->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}
