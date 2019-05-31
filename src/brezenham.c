/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brezenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:56:39 by judrion           #+#    #+#             */
/*   Updated: 2019/05/31 15:40:30 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void				draw_lines(t_vector3d *p, t_mlx *mlx)
{
	bresenham_line(p[0], p[1], mlx);
	bresenham_line(p[0], p[2], mlx);
}

static t_bresenham		*init_data_line(t_vector3d *p0, t_vector3d *p1)
{
	t_bresenham			*data_line;

	data_line = (t_bresenham*)ft_memalloc(sizeof(t_bresenham));
	if (!data_line)
		throw_error(DATA_LINE_INIT_FAILED);
	data_line->steep = abs(p1->y - p0->y) > abs(p1->x - p0->x);
	if (data_line->steep)
	{
		memswap(&p0->x, &p0->y, sizeof(int));
		memswap(&p1->x, &p1->y, sizeof(int));
	}
	if (p0->x > p1->x)
	{
		memswap(&p0->x, &p1->x, sizeof(int));
		memswap(&p0->y, &p1->y, sizeof(int));
	}
	data_line->delta_x = p1->x - p0->x;
	data_line->delta_y = abs(p1->y - p0->y);
	data_line->error = data_line->delta_x / 2;
	data_line->ystep = p0->y < p1->y ? 1 : -1;
	return (data_line);
}

void				bresenham_line(t_vector3d p0, t_vector3d p1, t_mlx *mlx)
{
	t_bresenham			*data_line;
	t_vector3d			coord;

	data_line = init_data_line(&p0, &p1);
	printf("[%d:%d] - [%d:%d]\n", p0.x, p0.y, p1.x, p1.y);
	coord.x = p0.x;
	coord.y = p0.y;
	while (coord.x <= p1.x)
	{
		if (data_line->steep)
			mlx_pixel_put(mlx->ptr, mlx->win, coord.y, coord.x, (0x00aaaaaa));
		else
			mlx_pixel_put(mlx->ptr, mlx->win, coord.x, coord.y, (0x00aaaaaa));
		data_line->error = data_line->error - data_line->delta_y;
		if (data_line->error < 0)
		{
			coord.y = coord.y + data_line->ystep;
			data_line->error = data_line->error + data_line->delta_x;
		}
		coord.x = coord.x + 1;
	}
	ft_memdel((void**)&data_line);
}

