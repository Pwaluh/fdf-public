/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:25:29 by judrion           #+#    #+#             */
/*   Updated: 2019/07/29 17:26:12 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			parallel_view(t_vector3d *coord)
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

void			isometric_view(t_vector3d *p, t_mlx *mlx)
{
	double		old_x;
	int			i;
	//double		u;
//	double		v;
//	double		alpha = 1;
	t_vector3d	offset;

	i = 0;
//TODO : ameliorer le calcul de l'offset (le sortir pour ne pas recalculer a chaque fois)
	offset.x = (IMG_WIDTH / 2) - (((mlx->padding * mlx->map->line_size) / 2) - ((mlx->padding * mlx->map->line_nb) / 2))  * cos(0.6);
	offset.y = (IMG_HEIGHT / 2) - (((mlx->padding * mlx->map->line_size) / 2) + ((mlx->padding * mlx->map->line_nb) / 2)) * sin(0.5);
	while (i < 3)
	{
		//u = p[i].x * cos(alpha) + p[i].y * cos(alpha + 2.0944) + p[i].z * cos(alpha - 2.0944);
		//v = p[i].x * sin(alpha) + p[i].y * sin(alpha + 2.0944) + p[i].z * sin(alpha - 2.0944);
		old_x = p[i].x;
		p[i].x = (p[i].x - p[i].y) * cos(0.6) + offset.x;
		p[i].y = (old_x + p[i].y) * sin(0.5) - p[i].z + offset.y;
		//p[i].x = u;
		//p[i].y = v;
		i = i + 1;
	}
}
