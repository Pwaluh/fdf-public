/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:59:58 by judrion           #+#    #+#             */
/*   Updated: 2019/05/21 19:23:15 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				throw_error(int error_code)
{
	if (error_code == USAGE)
		ft_putendl("Usage: ./fdf [file]");
	if (error_code == MLX_ERROR)
		ft_putendl("Error: can't initialise minilibX");
	if (error_code == MAP_ERROR)
		ft_putendl("Error: invalid map");
	if (error_code == FILE_INIT_FAILED)
		ft_putendl("Error: can't allocate memory for files structure.");
	if (error_code == MLX_INIT_FAILED)
		ft_putendl("Error: can't allocate memory for mlx structure.");
	exit(error_code);
}
