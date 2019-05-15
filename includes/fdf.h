/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:56:57 by judrion           #+#    #+#             */
/*   Updated: 2019/05/15 15:05:34 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef enum				e_error
{
	USAGE,
	MLX_ERROR,
	MAP_ERROR
}							t_error;

typedef struct				s_file
{
	int						*data;
	int						line_size;
	int						line_nb;
}							t_file;

typedef struct				s_mlx
{
	void					*ptr;
	void					*win;
}							t_mlx;

#endif
