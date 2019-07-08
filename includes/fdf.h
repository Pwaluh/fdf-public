/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:56:57 by judrion           #+#    #+#             */
/*   Updated: 2019/07/08 17:30:22 by judrion          ###   ########.fr       */
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

# define					IMG_WIDTH	2000
# define					IMG_HEIGHT	2000

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

typedef struct				s_img
{
	int						size_line;
	int						bpp;
	int						endian;
}							t_img;

typedef struct				s_mlx
{
	void					*ptr;
	void					*win;
	void					*img_ptr;
	int						*img_array;
	t_file					*map;
	t_img					*img;
	int						padding;
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


t_list				*read_file(const char *filepath, t_file *file);
void				parser(t_list *list, int *data);

int					key_hook(int keycode, t_mlx *mlx);
void				free_data(t_mlx *mlx, t_file *map);
void				throw_error(int error_code);
t_file				*load_file(const char *file);
void				render(t_mlx *mlx);
void				draw_lines(t_vector3d *p, t_mlx *mlx, int i);
void				bresenham_line(t_vector3d p0, t_vector3d p1, t_mlx *mlx);
void				put_pixel(t_mlx *mlx, int x, int y, int color);
#endif
