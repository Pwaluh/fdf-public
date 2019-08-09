/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:10:28 by judrion           #+#    #+#             */
/*   Updated: 2019/08/09 15:32:21 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycode.h"
#include <stdio.h>

int				key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == ESC_KEY)
	{
		ft_putendl("key hook triggered\n");
		free_data(mlx);
		mlx_destroy_window(mlx->ptr, mlx->win);
		ft_memdel((void**)&mlx);
		exit(0);
	}
	else if (keycode == NKPL_KEY || (keycode == NKMN_KEY && mlx->padding > 4))
	{
		if (mlx->new_img == 1)
		{
			mlx_destroy_image(mlx->ptr, mlx->img_ptr);
			mlx->img_ptr = mlx_new_image(mlx->ptr, IMG_WIDTH, IMG_HEIGHT);
			mlx->img_array = (int*)mlx_get_data_addr(mlx->img_ptr, \
				 &mlx->img.bpp, &mlx->img.size_line, &mlx->img.endian);
		}
		mlx->padding = keycode == NKPL_KEY ? mlx->padding * 1.1 : mlx->padding * 0.9;
		mlx->offset.x = (IMG_WIDTH / 2) - (((mlx->padding * mlx->map->line_size) / 2) - ((mlx->padding * mlx->map->line_nb) / 2))  * cos(0.6);
		mlx->offset.y = (IMG_HEIGHT / 2) - (((mlx->padding * mlx->map->line_size) / 2) + ((mlx->padding * mlx->map->line_nb) / 2)) * sin(0.5);
		render(mlx);
	}
	else if (keycode == ONE_KEYNUM)
	{
		mlx_destroy_image(mlx->ptr, mlx->img_ptr);
		mlx->img_ptr = mlx_new_image(mlx->ptr, IMG_WIDTH, IMG_HEIGHT);
		mlx->img_array = (int*)mlx_get_data_addr(mlx->img_ptr, \
				 &mlx->img.bpp, &mlx->img.size_line, &mlx->img.endian);
		mlx->view = ISO;
		render(mlx);
	}
	else if (keycode == TWO_KEYNUM)
	{
		mlx_destroy_image(mlx->ptr, mlx->img_ptr);
		mlx->img_ptr = mlx_new_image(mlx->ptr, IMG_WIDTH, IMG_HEIGHT);
		mlx->img_array = (int*)mlx_get_data_addr(mlx->img_ptr, \
				 &mlx->img.bpp, &mlx->img.size_line, &mlx->img.endian);
		mlx->view = PARA;
		render(mlx);
	}
	else if (keycode == 3) //f keycode
		mlx->fun = mlx->fun == 0 ? 1 : 0;
	else if (keycode == 15) //r keycode
	{
		mlx_destroy_image(mlx->ptr, mlx->img_ptr);
		mlx->img_ptr = mlx_new_image(mlx->ptr, IMG_WIDTH, IMG_HEIGHT);
		mlx->img_array = (int*)mlx_get_data_addr(mlx->img_ptr, \
				 &mlx->img.bpp, &mlx->img.size_line, &mlx->img.endian);
		mlx->padding = (double)(IMG_WIDTH / 2) / mlx->map->line_size;
		mlx->offset.x = (IMG_WIDTH / 2) - (((mlx->padding * mlx->map->line_size) / 2) - ((mlx->padding * mlx->map->line_nb) / 2))  * cos(0.6);
		mlx->offset.y = (IMG_HEIGHT / 2) - (((mlx->padding * mlx->map->line_size) / 2) + ((mlx->padding * mlx->map->line_nb) / 2)) * sin(0.5);
		render(mlx);
	}
	else if (keycode == 45) //n keycode
		mlx->new_img = mlx->new_img == 0 ? 1 : 0;
	else if (keycode == 37) //l keycode
	{
		mlx_destroy_image(mlx->ptr, mlx->img_ptr);
		mlx->img_ptr = mlx_new_image(mlx->ptr, IMG_WIDTH, IMG_HEIGHT);
		mlx->img_array = (int*)mlx_get_data_addr(mlx->img_ptr, \
				 &mlx->img.bpp, &mlx->img.size_line, &mlx->img.endian);
		mlx->lines = mlx->lines == 2 ? 3 : 2;
		render(mlx);
	}
	else if (keycode == 0)
	{
		mlx->lines = 0;
		render(mlx);
	}
	else
		printf("keycode : %d\n", keycode);
	return (0);
}
