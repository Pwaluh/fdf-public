/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brezenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:15:49 by judrion           #+#    #+#             */
/*   Updated: 2019/08/01 13:08:36 by judrion          ###   ########.fr       */
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
	while (coord.x < p1.x && (coord.x < IMG_WIDTH && coord.x > 0))
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

	if (x > 0 && x < IMG_WIDTH)
	{
		indice = (y * IMG_WIDTH) + x;
		if (indice < (IMG_WIDTH * IMG_HEIGHT) && indice > 0)
			mlx->img_array[indice] = mlx_get_color_value(mlx->ptr, color);
	}
}
