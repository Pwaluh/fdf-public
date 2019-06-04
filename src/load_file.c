/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:58:16 by judrion           #+#    #+#             */
/*   Updated: 2019/06/04 18:47:35 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_file			*load_file(const char *filepath)
{
	t_file		*file;

	ft_putstr("Loading : ");
	ft_putendl(filepath);
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
	read_file(filepath, file);
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

void			read_file(const char *filepath, t_file *file)
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
		ft_strdel(&str);
		file->line_nb = file->line_nb + 1;
	}
	file->line_size = count_line(full_file, file->line_nb);
	//file->data = convert_data_type(full_file, file->line_size * file->line_nb);
}

int				*convert_data_type(char *str, int size)
{
	int			*data;
	char		**splitted_data;
	int			i;

	data = (int*)ft_memalloc(sizeof(int) * size);
	if (data == NULL)
		throw_error(INIT_DATA_FAILED);
	splitted_data = ft_strsplit(str, ' ');
	if (splitted_data == NULL)
	{
		ft_memdel((void**)&data);
		throw_error(SPLITTED_DATA_FAILED);
	}
	i = 0;
	while (splitted_data[i])
	{
		data[i] = ft_atoi(splitted_data[i]);
		ft_strdel(&splitted_data[i]);
		i = i + 1;
	}
	ft_memdel((void**)splitted_data);
	return (data);
}

int			count_line(char *c_data, int line_nb)
{
	char		**splitted_data;
	int			i;

	i = 0;
	splitted_data = ft_strsplit(c_data, ' ');
	if (splitted_data == NULL)
		throw_error(SPLITTED_DATA_FAILED);
	printf("line_nb : %d\n", line_nb);
	while (splitted_data[i])
	{
		ft_strdel(&splitted_data[i]);
		i = i + 1;
	}
	ft_memdel((void**)splitted_data);
	return (i / line_nb);
}
