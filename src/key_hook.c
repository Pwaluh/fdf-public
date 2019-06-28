/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:10:28 by judrion           #+#    #+#             */
/*   Updated: 2019/06/17 11:51:58 by judrion          ###   ########.fr       */
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
	else
		printf("keycode : %d\n", keycode);
	return (0);
}
