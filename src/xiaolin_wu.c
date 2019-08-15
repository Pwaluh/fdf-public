/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin_wu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:46:29 by judrion           #+#    #+#             */
/*   Updated: 2019/08/15 15:36:26 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				xiaoline_wu_line(t_vector2d a, t_vector2d b, t_mlx *mlx)
{
	t_xiaolin_wu	data;
	t_vector2d		coord;

	data.steep = abs(b.y - a.y) > abs(b.x - a.x);
	if (data.steep)
	{

		if (a.x > b.x)
		{
			memswap(&(a.x), &(b.x), sizeof(int));
			memswap(&(a.y), &(b.y), sizeof(int));
		}
	}
	if (a.x > b.x)
	{
		if (!data.steep)
		{
			memswap(&(a.x), &(b.x), sizeof(int));
			memswap(&(a.y), &(b.y), sizeof(int));
		}
	}
	data.delta_x = b.x - a.x;
	data.delta_y = b.y - a.y;
	data.gradient = data.delta_y / data.delta_x;
	data.y = a.y + data.gradient;
	coord.x = a.x + 1;
	put_pixel(mlx, a, 1, 0x00ffffff);
	put_pixel(mlx, b, 1, 0x00ffffff);
	while (coord.x < b.x)
	{
		coord.y = (int)data.y;
		put_pixel(mlx, coord, (float)(1 - (data.y - (int)data.y)), 0x00ffffff);
		coord.y = (int)data.y + 1;
		put_pixel(mlx, coord, (float)(data.y - (int)data.y), 0x00ffffff);
		coord.x = coord.x + 1;
		data.y = data.y + data.gradient;
	}
}
