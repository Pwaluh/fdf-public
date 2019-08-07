/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brezenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:15:49 by judrion           #+#    #+#             */
/*   Updated: 2019/08/07 16:20:30 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	int					color;

	data_line = init_data_line(&p0, &p1);
	coord.x = p0.x;
	coord.y = p0.y;
	if (p0.z > 0)
		color = 0x00bb4444;
	else
		color = 0x00aaaaaa;
	while (coord.x < p1.x)
	{
		if (data_line->steep)
			put_pixel(mlx, coord.y, coord.x, color);
		else
			put_pixel(mlx, coord.x, coord.y, color);
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

void				put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int				indice;

	if ((x > 0 && x < IMG_WIDTH) && (y > 0 && y < IMG_HEIGHT))
	{
		indice = (y * IMG_WIDTH) + x;
		if (indice < (IMG_WIDTH * IMG_HEIGHT) && indice > 0)
			mlx->img_array[indice] = mlx_get_color_value(mlx->ptr, color);
	}
}

/*
void line(int x0, int y0, int x1, int y1, t_mlx *mlx) {

	int		color = 0x00648b91;
	int		dx = abs(x1-x0);
	int		sx = x0<x1 ? 1 : -1;
	int		dy = abs(y1-y0);
	int		sy = y0 < y1 ? 1 : -1;
	int		err = (dx > dy ? dx : -dy) / 2;
	int		e2;

	while(1){
		put_pixel(mlx, x0, y0, color);
		//setPixel(x0,y0);
		if (x0==x1 && y0==y1)
			break;
		e2 = err;
		if (e2 >-dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}
*/
