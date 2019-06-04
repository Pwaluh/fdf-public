/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:56:57 by judrion           #+#    #+#             */
/*   Updated: 2019/06/04 18:20:25 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <math.h>
# include <errno.h>
# include <fcntl.h>

typedef enum				e_error
{
	USAGE,
	MLX_ERROR,
	MAP_ERROR,
	FILE_INIT_FAILED,
	DATA_LINE_INIT_FAILED,
	MLX_INIT_FAILED,
	INIT_POINTS,
	INIT_DATA_FAILED,
	SPLITTED_DATA_FAILED,
	OPEN_FAIL
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


typedef struct				s_vector3d
{
	int						x;
	int						y;
	int						z;
}							t_vector3d;

typedef struct				s_bresenham
{
	int						delta_x;
	int						delta_y;
	int						error;
	int						ystep;
	int						steep;
}							t_bresenham;


int					*convert_data_type(char *str, int size);
int					count_line(char *c_data, int line_nb);
void				read_file(const char *filepath, t_file *file);

int					key_hook(int keycode, t_mlx *mlx);
void				free_data(t_mlx *mlx, t_file *map);
void				throw_error(int error_code);
t_file				*load_file(const char *file);
void				render(t_file *map, t_mlx *mlx);
void				draw_lines(t_vector3d *p, t_mlx *mlx);
void				bresenham_line(t_vector3d p0, t_vector3d p1, t_mlx *mlx);
#endif
