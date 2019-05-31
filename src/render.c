/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:32:57 by judrion           #+#    #+#             */
/*   Updated: 2019/05/31 14:42:26 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void			render_menu()
{
	ft_putendl("Menu");
}

static void			render_log()
{
	ft_putendl("Log");
}

static t_vector3d	*init_points(t_file *map, int i)
{
	t_vector3d		*p;

	p = (t_vector3d*)ft_memalloc(sizeof(t_vector3d) * 3);
	if (p == NULL)
		throw_error(INIT_POINTS);
	p[0].x = i % map->line_size;
	p[0].y = (i / map->line_size);
	p[0].z = map->data[i];
	if (p[0].x < map->line_size - 1)
	{
		p[1].x = p[0].x + 1;
		p[1].y = p[0].y;
		p[1].z = map->data[i + 1];
	}
	else
		p[1] = p[0];
	if (p[0].y < map->line_nb - 1)
	{
		p[2].x = p[0].x;
		p[2].y = p[0].y + 1;
		p[1].z = map->data[i + map->line_size];
	}
	else
		p[2] = p[0];
	return (p);
}

static void				apply_padding(t_vector3d *p, int i, t_file *map)
{
	t_vector3d		tmp;
	
	tmp.x = i % map->line_size;
	tmp.y = i / map->line_size;
	p[0].x = p[0].x * 10;
	p[0].y = p[0].y * 10;

	p[1].x = p[1].x * 10;
	p[1].y = p[1].y * 10;

	p[2].x = p[2].x * 10;
	p[2].y = p[2].y * 10;
}

void				render(t_file *map, t_mlx *mlx)
{
	int				i;
	t_vector3d		*p;

	i = 0;
	render_menu();
	while (i < map->line_size * map->line_nb)
	{
		p = init_points(map, i);
		apply_padding(p, i, map);
		draw_lines(p, mlx);
		ft_memdel((void**)&p);
		i = i + 1;
	}
	render_log();
}
