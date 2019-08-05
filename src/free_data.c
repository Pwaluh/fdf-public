/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 19:26:54 by judrion           #+#    #+#             */
/*   Updated: 2019/08/05 16:54:37 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycode.h"
#include <stdio.h>

void	free_data(t_mlx *mlx)
{
	printf("Free mlx struct\n");
	ft_memdel((void**)&mlx->map->data);
	ft_memdel((void**)&mlx->map);
	mlx_destroy_image(mlx->ptr, mlx->img_ptr);
}

void	memdel_size(t_list **list)
{
	t_list			*current;
	t_list			*next;

	current = *list;
	while (current)
	{
		next = current->next;
		printf("current : %p\t", current);
		printf("current->next : %p\t", current->next);
		printf("current->content : %p\t", current->content);
		printf("str : %s\n", current->content);
		current = next;
	}
}
