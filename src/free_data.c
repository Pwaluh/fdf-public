/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 19:26:54 by judrion           #+#    #+#             */
/*   Updated: 2019/08/04 14:50:33 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	free_data(t_mlx *mlx)
{
	printf("Free mlx struct\n");
	ft_memdel((void**)&mlx->map->data);
	ft_memdel((void**)&mlx->map);
	mlx_destroy_image(mlx->ptr, mlx->img_ptr);
	ft_memdel((void**)&mlx);
}
