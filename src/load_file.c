/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:58:16 by judrion           #+#    #+#             */
/*   Updated: 2019/06/28 17:05:23 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_file			*load_file(const char *filepath)
{
	t_file		*file;
	t_list		*file_line;

	if ((file = (t_file*)ft_memalloc(sizeof(t_file))) == NULL)
		throw_error(FILE_INIT_FAILED);
	file->line_nb = 0;
	file->line_size = 0;
	file_line = read_file(filepath, file);
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
		ft_lstadd(&full_file, new_elem);
		file->line_nb = file->line_nb + 1;
	}
	return (full_file);
}
