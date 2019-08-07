/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 12:40:03 by judrion           #+#    #+#             */
/*   Updated: 2019/08/07 18:40:11 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

/*
 *	TODO: think about a better parser;
 */

int			setup_lines(t_list *file_lines)
{
	t_list		*beg;
	char		*new_number;
	int		i;

	beg = file_lines;
	while(beg)
	{
		i = 0;
		while (*(char*)(beg->content + i))
		{
			new_number = ft_strchr((char*)(beg->content + i), ' ');
			if (new_number && ft_isdigit(*(new_number - 1)) == 1)
			{
				*new_number = '\0';
				beg->content_size = beg->content_size + 1;
				i = i + (new_number - (char*)(beg->content + i)) + 1;
			} 
			else
				i = i + 1;
		}
		beg = beg->next;
	}
	return (0);
}

void			parser(t_list *list, int *data)
{
	t_list		*beg;
	size_t		i;
	size_t		j;
	size_t		k;

	beg = list;
	i = 0;
		*(data + i) = 0;
	while (beg)
	{
		j = 0;
		k = 0;
		while (j < beg->content_size)
		{
			*(data + i) = ft_atoi((char*)(beg->content + k));
			k = k + ft_strlen((char*)(beg->content + k)) + 1;
			i = i + 1;
			j = j + 1;
		}
		beg = beg->next;
	}
}
