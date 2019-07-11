/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:56:30 by judrion           #+#    #+#             */
/*   Updated: 2019/07/10 14:24:22 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycode.h"
#include <stdio.h>

t_mlx			*init_mlx(void)
{
	t_mlx		*mlx;

	mlx = (t_mlx*)ft_memalloc(sizeof(t_mlx));
	if (mlx == NULL)
		throw_error(MLX_INIT_FAILED);
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, IMG_WIDTH, IMG_HEIGHT, "fdf");
	mlx->img = (t_img*)ft_memalloc(sizeof(t_img));
	if (mlx->img == NULL)
		throw_error(MLX_INIT_FAILED);
	mlx->img->bpp = 32;
	mlx->img->size_line = IMG_WIDTH;
	mlx->img->endian = 0;
	mlx->img_ptr = mlx_new_image(mlx->ptr, IMG_WIDTH, IMG_HEIGHT);
	mlx->img_array = (int*)mlx_get_data_addr(mlx->img_ptr, \
					 &mlx->img->bpp, &mlx->img->size_line, &mlx->img->endian);
	return (mlx);
}

static void			scale_z(t_mlx *mlx)
{
	int				i;
	int				min;
	int				max;

	i = 0;
	min = 0;
	max = 0;
	while (i < mlx->map->line_size * mlx->map->line_nb)
	{
		if (mlx->map->data[i] < min)
			min = mlx->map->data[i];
		if (mlx->map->data[i] > max)
			max = mlx->map->data[i];
		i = i + 1;
	}
	i = 0;
	while (i < mlx->map->line_size * mlx->map->line_nb)
	{
		if (mlx->map->data[i] != 0)
			mlx->map->data[i] = (double)mlx->map->data[i] / (max - min) * 100;
		i = i + 1;
	}
}

int				main(int argc, char **argv)
{
	t_mlx		*mlx;

	if (argc != 2)
		throw_error(USAGE);
	if ((mlx = init_mlx()) == NULL)
		throw_error(MLX_ERROR);
	if ((mlx->map = load_file(argv[1])) == NULL)
		throw_error(MAP_ERROR);
	mlx->padding = (double)(IMG_WIDTH / 2) / mlx->map->line_size;
	printf("size_line : %d\n", mlx->map->line_size);
	printf("padding : %f\n", mlx->padding);
	scale_z(mlx);
	render(mlx);
//	free_data(mlx, map);
	mlx_hook(mlx->win, KEYPRESS, KPMASK, &key_hook, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
