/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:56:30 by judrion           #+#    #+#             */
/*   Updated: 2019/08/15 15:34:41 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycode.h"

int				biggest_line(t_list *list)
{
	int			biggest;
	t_list		*beg;

	biggest = 0;
	beg = list;
	while (list)
	{
		if ((int)list->content_size > biggest)
			biggest = list->content_size;
		list = list->next;
	}
	list = beg;
	return (biggest);
}

t_mlx			*init_mlx(void)
{
	t_mlx		*mlx;

	mlx = (t_mlx*)ft_memalloc(sizeof(t_mlx));
	if (mlx == NULL)
		throw_error(MLX_INIT_FAILED, mlx);
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, IMG_WIDTH, IMG_HEIGHT, "fdf");
	if (mlx->win == NULL)
		throw_error(WINDOW_ALLOC_FAILED, mlx);
	mlx->img.bpp = 32;
	mlx->img.size_line = IMG_WIDTH;
	mlx->img.endian = 0;
	mlx->img_ptr = mlx_new_image(mlx->ptr, IMG_WIDTH, IMG_HEIGHT);
	if (mlx->img_ptr == NULL)
		throw_error(IMAGE_ALLOC_FAILED, mlx);
	mlx->img_array = (int*)mlx_get_data_addr(mlx->img_ptr, \
					&mlx->img.bpp, &mlx->img.size_line, &mlx->img.endian);
	mlx->view = ISO;
	mlx->fun = 0;
	mlx->new_img = 1;
	mlx->lines = 2;
	mlx->line = (t_bresenham*)ft_memalloc(sizeof(t_bresenham));
	return (mlx);
}

void			scale_z(t_mlx *mlx)
{
	int			i;
	int			min;
	int			max;

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

int				loop(t_mlx *mlx)
{
	if (mlx->fun == 1)
	{
		key_hook(NKPL_KEY, mlx);
		usleep(7500);
	}
	else
		usleep(50000);
	return (1);
}

int				main(int argc, char **argv)
{
	t_mlx		*mlx;

	mlx = NULL;
	if (argc != 2)
		throw_error(USAGE, mlx);
	if ((mlx = init_mlx()) == NULL)
		throw_error(MLX_ERROR, mlx);
	if ((mlx->map = load_file(argv[1], mlx)) == NULL)
		throw_error(MAP_ERROR, mlx);
	mlx->padding = (double)(IMG_WIDTH / 2) / mlx->map->line_size;
	isometric_offset(mlx);
	render(mlx);
	mlx_hook(mlx->win, KP, KPMASK, &key_hook, mlx);
	mlx_loop_hook(mlx->ptr, loop, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
