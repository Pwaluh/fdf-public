/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:25:29 by judrion           #+#    #+#             */
/*   Updated: 2019/08/05 13:41:21 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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

	i = 0;
//TODO : ameliorer le calcul de l'offset (le sortir pour ne pas recalculer a chaque fois)
	while (i < 3)
	{
		old_x = p[i].x;
		p[i].x = (p[i].x - p[i].y) * cos(0.523599) + mlx->offset.x;
		p[i].y = (old_x + p[i].y) * sin(0.523599) - p[i].z + mlx->offset.y;
		i = i + 1;
	}
}
