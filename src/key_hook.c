/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:10:28 by judrion           #+#    #+#             */
/*   Updated: 2019/08/12 17:22:56 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycode.h"
#include <stdio.h>

void				isometric_offset(t_mlx *mlx)
{
	mlx->offset.x = (IMG_WIDTH / 2) \
					- (((mlx->padding * mlx->map->line_size) / 2) \
					- ((mlx->padding * mlx->map->line_nb) / 2)) \
					* cos(0.523599);
	mlx->offset.y = (IMG_HEIGHT / 2) \
					- (((mlx->padding * mlx->map->line_size) / 2) \
					+ ((mlx->padding * mlx->map->line_nb) / 2)) \
					* sin(0.523599);
}

void				parallel_offset(t_mlx *mlx)
{
	mlx->offset.x = (IMG_WIDTH / 2) \
					- ((mlx->map->line_size / 2) * mlx->padding);
	mlx->offset.y = (IMG_HEIGHT / 2) \
					- ((mlx->map->line_nb / 2) * mlx->padding);
}

void				move_offset(t_mlx *mlx, int keycode)
{
	if (keycode == UP_KEY || keycode == DOWN_KEY)
	{
		if (keycode == UP_KEY)
			mlx->offset.y = mlx->offset.y + (10 * mlx->padding);
		else
			mlx->offset.y = mlx->offset.y - (10 * mlx->padding);
	}
	else
	{
		if (keycode == LEFT_KEY)
			mlx->offset.x = mlx->offset.x + (10 * mlx->padding);
		else
			mlx->offset.x = mlx->offset.x - (10 * mlx->padding);
	}
}

int					key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == ESC_KEY)
	{
		free_data(mlx);
		mlx_destroy_window(mlx->ptr, mlx->win);
		ft_memdel((void**)&mlx);
		exit(0);
	}
	else if (keycode == NKPL_KEY || (keycode == NKMN_KEY && mlx->padding > 4))
	{
		mlx->padding = keycode == NKPL_KEY ? \
					mlx->padding * 1.1 : mlx->padding * 0.9;
		mlx->view == ISO ? isometric_offset(mlx) : parallel_offset(mlx);
	}
	else if (keycode == ONE_KEYNUM || keycode == TWO_KEYNUM)
	{
		mlx->view = keycode == ONE_KEYNUM ? ISO : PARA;
		mlx->view == ISO ? isometric_offset(mlx) : parallel_offset(mlx);
	}
	else
		key_hook_2(keycode, mlx);
	if (mlx->new_img == 1)
		create_image(mlx);
	render(mlx);
	return (0);
}

int					key_hook_2(int keycode, t_mlx *mlx)
{
	if (keycode == 3)
		mlx->fun = mlx->fun == 0 ? 1 : 0;
	else if (keycode == 15)
	{
		mlx->padding = (double)(IMG_WIDTH / 2) / mlx->map->line_size;
		isometric_offset(mlx);
	}
	else if (keycode == 45)
		mlx->new_img = mlx->new_img == 0 ? 1 : 0;
	else if (keycode == 37 || keycode == 0)
	{
		mlx->lines = mlx->lines == 2 ? 3 : 2;
		mlx->lines = keycode == 0 ? 0 : mlx->lines;
	}
	else if (keycode == UP_KEY || keycode == DOWN_KEY
			|| keycode == LEFT_KEY || keycode == RIGHT_KEY)
		move_offset(mlx, keycode);
	return (0);
}
