/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:58:16 by judrion           #+#    #+#             */
/*   Updated: 2019/05/31 14:24:06 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_file			*load_file(const char *filepath)
{
	t_file		*file;
	int			i = 0;

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
	while (i < 9)
	{
		file->data[i] = i;
		i = i + 1;
	}
	file->line_size = 3;
	file->line_nb = 3;
	return (file);
}
