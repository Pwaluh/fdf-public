/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:59:58 by judrion           #+#    #+#             */
/*   Updated: 2019/05/15 15:09:01 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void				throw_error(int error_code)
{
	if (error_code == USAGE)
		ft_putendl("Usage: ./fdf [file]");
	if (error_code == MLX_ERROR)
		ft_putndel("Error: can't initialise minilibX");
	if (error_code == MAP_ERROR)
		ft_putendl("Error: invalid map");
	exit(error_code);
}
