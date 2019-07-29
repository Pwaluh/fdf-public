/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:10:28 by judrion           #+#    #+#             */
/*   Updated: 2019/07/29 20:03:04 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycode.h"
#include <stdio.h>

int				key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == ESC_KEY)
	{
		ft_putendl("key hook triggered");
	//	free_data(mlx, map);
		mlx_destroy_window(mlx->ptr, mlx->win);
		exit(0);
	}
	else if (keycode == PL_KEY)
	{
		mlx->padding = mlx->padding + 1;
		render(mlx);
	}
	else if (keycode == MN_KEY && mlx->padding > 1)
	{
		mlx->padding = mlx->padding - 1;
		render(mlx);
	}
	else if (keycode == ONE_KEYNUM)
	{
		mlx_destroy_image(mlx->ptr, mlx->img_ptr);
		mlx->img_ptr = mlx_new_image(mlx->ptr, IMG_WIDTH, IMG_HEIGHT);
		mlx->img_array = (int*)mlx_get_data_addr(mlx->img_ptr, \
					 &mlx->img->bpp, &mlx->img->size_line, &mlx->img->endian);
		mlx->view = ISO;
		render(mlx);
	}
	else if (keycode == TWO_KEYNUM)
	{
		mlx_destroy_image(mlx->ptr, mlx->img_ptr);
		mlx->img_ptr = mlx_new_image(mlx->ptr, IMG_WIDTH, IMG_HEIGHT);
		mlx->img_array = (int*)mlx_get_data_addr(mlx->img_ptr, \
					 &mlx->img->bpp, &mlx->img->size_line, &mlx->img->endian);
		mlx->view = PARA;
		render(mlx);
	}
	else
		printf("keycode : %d\n", keycode);
	return (0);
}
