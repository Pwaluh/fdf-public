/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:32:57 by judrion           #+#    #+#             */
/*   Updated: 2019/07/29 18:13:25 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void				draw_lines(t_vector3d *p, t_mlx *mlx)
{
	bresenham_line(p[0], p[1], mlx);
	bresenham_line(p[0], p[2], mlx);
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
	if (i < (map->line_size * map->line_nb) - map->line_size)
	{
		p[2].x = p[0].x;
		p[2].y = p[0].y + 1;
		p[2].z = map->data[i + map->line_size];
	}
	else
		p[2] = p[0];
	return (p);
}

static void				apply_padding(t_vector3d *p, t_mlx *mlx)
{
	//TODO : ameliorer le padding
	p[0].x = p[0].x * mlx->padding;
	p[0].y = p[0].y * mlx->padding;
	p[1].x = p[1].x * mlx->padding;
	p[1].y = p[1].y * mlx->padding;
	p[2].x = p[2].x * mlx->padding;
	p[2].y = p[2].y * mlx->padding;
}
void				render(t_mlx *mlx)
{
	int				i = 0;
	t_vector3d		*p;

	i = 0;
	while (i < (mlx->map->line_size * mlx->map->line_nb))
	{
		p = init_points(mlx->map, i);
		apply_padding(p, mlx);
		if (mlx->view == PARA)
			parallel_view(p);
		else
			isometric_view(p, mlx);
		draw_lines(p, mlx);
		ft_memdel((void**)&p);
		i = i + 1;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_ptr, 0, 0);
}
