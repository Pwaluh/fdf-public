/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:58:16 by judrion           #+#    #+#             */
/*   Updated: 2019/06/06 17:54:37 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_file			*load_file(const char *filepath)
{
	t_file		*file;
	char		*str;

	if ((file = (t_file*)ft_memalloc(sizeof(t_file))) == NULL)
		throw_error(FILE_INIT_FAILED);
	file->data = (int*)ft_memalloc(sizeof(int) * 9);
	if (file->data == NULL)
	{
		ft_memdel((void**)&file);
		throw_error(FILE_INIT_FAILED);
	}
	file->line_nb = 0;
	file->line_size = 0;
	str = read_file(filepath, file);
	file->data = parse(str, file->line_nb, &file->line_size);
	printf("file->size : %d(c) - %d(l)\n", file->line_size, file->line_nb);
	return (file);
}
static char		*ft_strjoin_free(char *s1, char *s2)
{
	char		*tmp;

	tmp = s1;
	s1 = ft_strjoin(s1, " ");
	ft_strdel(&tmp);
	tmp = s1;
	s1 = ft_strjoin(s1, s2);
	ft_strdel(&tmp);
	ft_strdel(&s2);
	return (s1);
}

char			*read_file(const char *filepath, t_file *file)
{
	int			fd;
	char		*str;
	char		*full_file;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		throw_error(OPEN_FAIL);
	while (get_next_line(fd, &str) > 0)
	{
		if (file->line_nb > 0)
			full_file = ft_strjoin_free(full_file, str);
		else
			full_file = ft_strdup(str);
		file->line_nb = file->line_nb + 1;
	}
	close(fd);
	return (full_file);
}

int			*parse(char *c_data, int nb_line, int *line_size)
{
	char		**splitted_data;
	int			i;
	int			*i_data;

	i = 0;
	splitted_data = ft_strsplit(c_data, ' ');
	if (splitted_data == NULL)
		throw_error(SPLITTED_DATA_FAILED);
	while (splitted_data[i])
		i = i + 1;
	i_data = (int*)ft_memalloc(sizeof(int) * i);
	*line_size = i / nb_line;
	i = 0;
	while (splitted_data[i])
	{
		i_data[i] = ft_atoi(splitted_data[i]);
		ft_strdel(&splitted_data[i]);
		i = i + 1;
	}
	ft_memdel((void**)splitted_data);
	return (i_data);
}
