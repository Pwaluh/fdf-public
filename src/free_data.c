/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 19:26:54 by judrion           #+#    #+#             */
/*   Updated: 2019/05/28 17:09:41 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_data(t_mlx *mlx, t_file *map)
{
	mlx_destroy_image(mlx->ptr,mlx->ptr);
	ft_memdel((void**)&mlx);
	ft_memdel((void**)&map->data);
	ft_memdel((void**)&map);
}
