/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:58:16 by judrion           #+#    #+#             */
/*   Updated: 2019/08/15 15:21:21 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_file			*load_file(const char *filepath, t_mlx *mlx)
{
	t_file		*file;
	t_list		*file_line;
	int			full_size;

	if ((file = (t_file*)ft_memalloc(sizeof(t_file))) == NULL)
		throw_error(FILE_INIT_FAILED, mlx);
	file->line_nb = 0;
	full_size = 0;
	file_line = read_file(filepath, file, mlx);
	ft_reverse_list(&file_line);
	setup_lines(file_line);
	file->line_size = biggest_line(file_line);
	file->data = (int*)ft_memalloc(sizeof(int) \
			* (file->line_size * file->line_nb));
	if (file->data)
		parser(file_line, file->data);
	free_list(&file_line);
	return (file);
}

static int		setup_new_elem(char *str, t_list **full_file)
{
	t_list		*new_elem;

	new_elem = ft_lstnew(NULL, 0);
	if (new_elem == NULL)
		return (-1);
	new_elem->content = (void*)str;
	new_elem->content_size = 1;
	ft_lstadd(full_file, new_elem);
	return (0);
}

t_list			*read_file(const char *filepath, t_file *file, t_mlx *mlx)
{
	int			fd;
	char		*str;
	t_list		*full_file;
	int			gnl;

	full_file = NULL;
	str = NULL;
	if ((fd = open(filepath, O_RDONLY)) == 0)
		throw_error(OPEN_FAIL, mlx);
	while ((gnl = get_next_line(fd, &str)) > 0)
	{
		if (setup_new_elem(str, &full_file) == -1)
		{
			gnl = -1;
			break ;
		}
		file->line_nb = file->line_nb + 1;
	}
	close(fd);
	if (gnl == -1)
	{
		free_list(&full_file);
		throw_error(FILE_ERROR, mlx);
	}
	return (full_file);
}
