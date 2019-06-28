/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:56:30 by judrion           #+#    #+#             */
/*   Updated: 2019/06/27 18:04:57 by judrion          ###   ########.fr       */
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
	mlx->win = mlx_new_window(mlx->ptr, 1000, 1000, "fdf");
	mlx->padding = 2;
	return (mlx);
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
//	render(mlx);
//	free_data(mlx, map);
	mlx_hook(mlx->win, KEYPRESS, KPMASK, &key_hook, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
