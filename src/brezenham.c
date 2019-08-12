/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brezenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:15:49 by judrion           #+#    #+#             */
/*   Updated: 2019/08/12 16:34:58 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				init_line(t_vector3d *p0, t_vector3d *p1, \
							t_bresenham *line)
{
	line->steep = abs(p1->y - p0->y) > abs(p1->x - p0->x);
	if (line->steep)
	{
		memswap(&p0->x, &p0->y, sizeof(int));
		memswap(&p1->x, &p1->y, sizeof(int));
	}
	if (p0->x > p1->x)
	{
		memswap(&p0->x, &p1->x, sizeof(int));
		memswap(&p0->y, &p1->y, sizeof(int));
	}
	line->delta_x = p1->x - p0->x;
	line->delta_y = abs(p1->y - p0->y);
	line->error = line->delta_x / 2;
	line->ystep = p0->y < p1->y ? 1 : -1;
}

void				bresenham_line(t_vector3d p0, t_vector3d p1, t_mlx *mlx)
{
	t_vector3d			coord;
	int					color;

	init_line(&p0, &p1, mlx->line);
	coord.x = p0.x;
	coord.y = p0.y;
	if (p0.z > 0)
		color = 0x00bb4444;
	else
		color = 0x00aaaaaa;
	while (coord.x < p1.x)
	{
		if (mlx->line->steep)
			put_pixel(mlx, coord.y, coord.x, color);
		else
			put_pixel(mlx, coord.x, coord.y, color);
		mlx->line->error = mlx->line->error - mlx->line->delta_y;
		if (mlx->line->error < 0)
		{
			coord.y = coord.y + mlx->line->ystep;
			mlx->line->error = mlx->line->error + mlx->line->delta_x;
		}
		coord.x = coord.x + 1;
	}
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
