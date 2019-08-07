/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:58:16 by judrion           #+#    #+#             */
/*   Updated: 2019/08/07 18:40:05 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>


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
	setup_lines(file_line);
	file->line_size = biggest_line(file_line);
	file->data = (int*)ft_memalloc(sizeof(int) * (file->line_size * file->line_nb));
	if (file->data)
		parser(file_line, file->data);
	free_list(&file_line);
	return (file);
}

t_list			*read_file(const char *filepath, t_file *file)
{
	int			fd;
	char		*str;
	t_list		*full_file;
	t_list		*new_elem;

	full_file = NULL;
	str = NULL;
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		throw_error(OPEN_FAIL);
	while (get_next_line(fd, &str) > 0)
	{
		new_elem = ft_lstnew(NULL, 0);
		new_elem->content = (void*)str;
		new_elem->content_size = 1;
		ft_lstadd(&full_file, new_elem);
		file->line_nb = file->line_nb + 1;
	}
	return (full_file);
}

void		print_list(t_list *list)
{
	int		i = 0;
	t_list *tmp;

	tmp = list;
	ft_putendl("========================================================================================================");
	while (tmp)
	{
		printf("%i\t(%zu)\t%p\t%s\n", i, tmp->content_size, tmp->content, (char*)tmp->content);
		i = i + 1;
		tmp = tmp->next;
	}
	ft_putendl("========================================================================================================");
}
