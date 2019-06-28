/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:11:58 by judrion           #+#    #+#             */
/*   Updated: 2019/06/18 16:07:54 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\0' || c == '\r')
		return (1);
	return (0);
}

char	*copy(char *str, int i)
{
	char	*output;
	int		j = 0;

	output = (char*)malloc(sizeof(char) * (i + 1));
	if (output == NULL)
		return (output);
	while (j < i)
	{
		output[j] = str[j];
		j = j + 1;
	}
	return (output);
}

char	**ft_split(char *str)
{
	char	**tab;
	char	*tmp;
	int		i = 0;
	int		j = 0;
	int		nb_mot = 0;

	if (*str == '\0')
	{
		tab = (char**)malloc(sizeof(char*) * 1);
		*tab = NULL;
		return (tab);
	}
	tmp = str;
	while (*str)
	{
		if (is_whitespace(*str) == 1 && is_whitespace(*(str - 1)) == 0)
			j = j + 1;
		str++;
	}
	if (is_whitespace(*str) == 1 && is_whitespace(*(str - 1)) == 0)
		j = j + 1;
	tab = (char**)malloc(sizeof(char*) * (j + 1));
	if (tab == NULL)
		return (tab);
	nb_mot = j;
	j = 0;
	str = tmp;
	while (*str)
	{
		if (is_whitespace(*str) == 0)
			i = i + 1;
		if (is_whitespace(*str) == 1 && is_whitespace(*(str - 1)) == 0)
		{
			tab[j] = copy(str - i, i);
			j = j + 1;
			i = 0;
		}
		str++;
	}
	if (is_whitespace(*str) == 1 && is_whitespace(*(str - 1)) == 0)
		tab[j] = copy(str - i, i);
	tab[nb_mot] = NULL;
	return (tab);
}

