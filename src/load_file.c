/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:58:16 by judrion           #+#    #+#             */
/*   Updated: 2019/08/04 15:05:03 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		print_list(t_list *list)
{
	int		i = 0;

	while (list)
	{
		printf("elem n°%d\t%p->%p\n", i, list, list->next);
		if (list->content_size == 0)
			printf("\t(%zu) - %s\n", ft_strlen((char*)list->content), (char*)list->content);
		else
			printf("\t(%zu) - %s\n", list->content_size, (char*)list->content);
		i = i + 1;
		list = list->next;
	}
}

static int			setup_lines(t_list *file_lines)
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

static int		biggest_line(t_list *list)
{
	int		biggest;
	t_list		*beg;

	biggest = 0;
	beg = list;
	while (list)
	{
		if ((int)list->content_size > biggest)
			biggest = list->content_size;
		list = list->next;
	}
	list = beg;
	return (biggest);
}

void			parser(t_list *list, int *data)
{
	t_list		*beg;
	size_t		i;
	size_t		j;
	size_t		k;
	size_t		string_size;

	beg = list;
	i = 0;
	while (beg)
	{
		string_size = ft_strlen((char*)beg->content);
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

t_file			*load_file(const char *filepath)
{
	t_file		*file;
	t_list		*file_line;
	int		full_size;

	if ((file = (t_file*)ft_memalloc(sizeof(t_file))) == NULL)
		throw_error(FILE_INIT_FAILED);
	file->line_nb = 0;
	full_size = 0;
	file_line = read_file(filepath, file);
	//print_list(file_line);
	setup_lines(file_line);
	ft_reverse_list(&file_line);
	file->line_size = biggest_line(file_line);
	full_size = file->line_size * file->line_nb;
	file->data = (int*)ft_memalloc(sizeof(int) * full_size);
	if (!file->data)
		throw_error(FILE_INIT_FAILED);
	parser(file_line, file->data);
	//TODO : free la liste
	return (file);
}

t_list			*read_file(const char *filepath, t_file *file)
{
	int			fd;
	char		*str;
	t_list		*full_file;
	t_list		*new_elem;

	full_file = NULL;
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		throw_error(OPEN_FAIL);
	while (get_next_line(fd, &str) > 0)
	{
		new_elem = ft_lstnew(NULL, 0);
		new_elem->content = str;
		new_elem->content_size = 1;
		ft_lstadd(&full_file, new_elem);
		file->line_nb = file->line_nb + 1;
	}
	return (full_file);
}

