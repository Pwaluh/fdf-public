/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:59:58 by judrion           #+#    #+#             */
/*   Updated: 2019/08/15 16:51:09 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				throw_error(int error_code, t_mlx *mlx)
{
	if (error_code == USAGE)
	{
		ft_putendl("Usage: ./fdf [file]");
		exit(error_code);
	}
	if (error_code == MLX_ERROR)
		ft_putendl("Error: can't initialise minilibX");
	if (error_code == MAP_ERROR)
		ft_putendl("Error: invalid map");
	if (error_code == FILE_INIT_FAILED)
		ft_putendl("Error: can't allocate memory for files structure.");
	if (error_code == MLX_INIT_FAILED)
		ft_putendl("Error: can't allocate memory for mlx structure.");
	if (error_code == FILE_ERROR)
		ft_putendl("Error: not a valid file.");
	if (error_code == OPEN_FAIL)
		ft_putendl("Error: can't open file.");
	free_data(mlx);
	mlx_destroy_window(mlx->ptr, mlx->win);
	ft_memdel((void**)mlx);
	exit(error_code);
}
