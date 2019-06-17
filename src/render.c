/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:32:57 by judrion           #+#    #+#             */
/*   Updated: 2019/06/17 10:26:53 by judrion          ###   ########.fr       */
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
		p[2].z = map->data[i + map->line_size];
	}
	else
		p[2] = p[0];
/*	j = 0;
	while (j < 3)
	{
		printf("p[%d] [%d:%d:%d]\n", j, p[j].x, p[j].y, p[j].z);
		j = j + 1;
	} */
	return (p);
}

static void				apply_padding(t_vector3d *p, t_mlx *mlx)
{
	p[0].x = p[0].x * mlx->padding;
	p[0].y = p[0].y * mlx->padding;
	p[0].z = p[0].z * mlx->padding / 100;
	p[1].x = p[1].x * mlx->padding;
	p[1].y = p[1].y * mlx->padding;
	p[1].z = p[1].z * mlx->padding / 100;
	p[2].x = p[2].x * mlx->padding;
	p[2].y = p[2].y * mlx->padding;
	p[2].z = p[2].z * mlx->padding / 100;
}

/*
static void			parallel_view(t_vector3d *coord)
{
	int				i;

	i = 0;
	while (i < 3)
	{
		coord[i].x = coord[i].x + (0.7 * coord[i].z) + 10;
		coord[i].y = coord[i].y + (0.7 / 2) * coord[i].z + 10;
		i = i + 1;
	}
}
*/

static void			isometric_view(t_vector3d *p)
{
	double		old_x;
	int			i;
	t_vector3d	offset;

	i = 0;
//TODO : ameliorer le calcul de l'offset
	offset.x = (IMG_WIDTH / 2) - ((IMG_WIDTH / 2) - (IMG_HEIGHT / 2)) * cos(0.5);
	offset.y = (IMG_HEIGHT / 2) - ((IMG_WIDTH / 2) + (IMG_HEIGHT / 2)) * sin(0.5);
	while (i < 3)
	{
		old_x = p[i].x;
		p[i].x = (p[i].x - p[i].y) * cos(0.5) + offset.x;
		p[i].y = (old_x + p[i].y) * sin(0.5) - p[i].z + offset.y;
		i = i + 1;
	}
}

void				render(t_mlx *mlx)
{
	int				i;
	t_vector3d		*p;

	i = 0;
	render_menu();
	while (i < mlx->map->line_size * mlx->map->line_nb)
	{
		p = init_points(mlx->map, i);
		apply_padding(p, mlx);
		isometric_view(p);
		draw_lines(p, mlx);
		ft_memdel((void**)&p);
		i = i + 1;
	}
	render_log();
}
