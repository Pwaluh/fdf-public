/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 15:38:24 by judrion           #+#    #+#             */
/*   Updated: 2019/08/12 16:36:05 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				create_image(t_mlx *mlx)
{
	if (mlx->img_ptr != NULL)
		mlx_destroy_image(mlx->ptr, mlx->img_ptr);
	mlx->img_ptr = mlx_new_image(mlx->ptr, IMG_WIDTH, IMG_HEIGHT);
	if (mlx->img_ptr == NULL)
		throw_error(IMAGE_ALLOC_FAILED, mlx);
	mlx->img_array = (int*)mlx_get_data_addr(mlx->img_ptr, \
					&mlx->img.bpp, &mlx->img.size_line, &mlx->img.endian);
}
