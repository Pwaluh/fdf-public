/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:11:58 by judrion           #+#    #+#             */
/*   Updated: 2019/06/10 17:04:08 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_count_word(const char *s, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = *(s + i) != c && *(s + i) ? 1 : 0;
	while (*(s + i))
	{
		if (*(s + i) != c && (i != 0 && *(s + i - 1) == c))
			j = j + 1;
		i = i + 1;
	}
	return (j);
}

static void		ft_clean_split(char **words)
{
	size_t		i;

	i = 0;
	while (*(words + i) != NULL)
	{
		free(*(words + i));
		*(words + i) = NULL;
		i = i + 1;
	}
	free(words);
}

static char		**ft_split_words(const char *s, char c, size_t nb_word, \
		char **words)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	while (i < nb_word)
	{
		k = 0;
		while (s[j] == c)
			j++;
		while (s[j + k] != c && s[j + k])
			k++;
		if (!(words[i] = ft_strsub(s, j, k)))
		{
			ft_clean_split(words);
			return (NULL);
		}
		i++;
		j = j + k;
	}
	words[i] = NULL;
	return (words);
}

char			**ft_strsplit(const char *s, char c)
{
	size_t		nb_word;
	char		**words;

	if (s == NULL)
		return (NULL);
	nb_word = ft_count_word(s, c);
	words = (char**)ft_memalloc(sizeof(char*) * nb_word + 1);
	if (words == NULL)
		return (NULL);
	words = ft_split_words(s, c, nb_word, words);
	return (words);
}
