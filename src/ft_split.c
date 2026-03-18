/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parenas- <parenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:05:36 by parenas-          #+#    #+#             */
/*   Updated: 2026/03/18 16:58:27 by parenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**ft_split(char const *s, char c);
static char	*fill_word(const char *str, int start, int end);
static int	count_words(char const *str, char c);
static void	*free_everything(char **strs, int count);
static void	initiate_vars(int *i, int *j, int *start_word);

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**res;
	int		j;
	int		start_word;

	initiate_vars(&i, &j, &start_word);
	res = malloc(((count_words(s, c)) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start_word < 0)
			start_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start_word >= 0)
		{
			res[j] = fill_word(s, start_word, i);
			if (!res[j])
				return (free_everything(res, j));
			start_word = -1;
			j++;
		}
		i++;
	}
	res[j] = 0;
	return (res);
}

static void	initiate_vars(int *i, int *j, int *start_word)
{
	*i = 0;
	*j = 0;
	*start_word = -1;
}

static void	*free_everything(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(strs[i++]);
	free(strs);
	return (NULL);
}

static char	*fill_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = str[start++];
	word[i] = 0;
	return (word);
}

static int	count_words(char const *str, char c)
{
	int	counter;
	int	boolean;

	counter = 0;
	boolean = 0;
	while (*str)
	{
		if (*str != c && boolean == 0)
		{
			counter++;
			boolean = 1;
		}
		else if (*str == c)
			boolean = 0;
		str++;
	}
	return (counter);
}
