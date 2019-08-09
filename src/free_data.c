/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 19:26:54 by judrion           #+#    #+#             */
/*   Updated: 2019/08/09 10:11:01 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycode.h"
#include <stdio.h>

void	free_data(t_mlx *mlx)
{
	printf("Free mlx struct\n");
	ft_memdel((void**)&mlx->data_line);
	ft_memdel((void**)&mlx->map->data);
	ft_memdel((void**)&mlx->map);
	mlx_destroy_image(mlx->ptr, mlx->img_ptr);
}

void	free_list(t_list **list)
{
	t_list			*current;
	t_list			*next;

	current = *list;
	while (current)
	{
		next = current->next;
		ft_strdel((char**)&(current->content));
		ft_memdel((void**)&(current));
		current = next;
	}
}
