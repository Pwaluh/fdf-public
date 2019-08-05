/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:56:57 by judrion           #+#    #+#             */
/*   Updated: 2019/08/05 14:13:02 by judrion          ###   ########.fr       */
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

# define					IMG_WIDTH	2880
# define					IMG_HEIGHT	1440
# define					ONE_KEYNUM	83
# define					TWO_KEYNUM	84
# define					ISO			0
# define					PARA		1

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

typedef struct				s_vector2d
{
	int						x;
	int						y;
}							t_vector2d;

typedef struct				s_vector3d
{
	int						x;
	int						y;
	int						z;
}							t_vector3d;

typedef struct				s_file
{
	int						*data;
	int						line_size;
	int						line_nb;
}							t_file;

typedef struct				s_key_hook
{
	int						fun;
}							t_key_hook;

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
	t_img					img;
	t_vector3d				offset;
	double					padding;
	int						view;
	int						fun;
	int						new_img;
	int						lines;
}							t_mlx;

typedef struct				s_bresenham
{
	int						delta_x;
	int						delta_y;
	int						error;
	int						ystep;
	int						steep;
}							t_bresenham;

typedef struct				s_xiaolin_wu
{
	int						steep;
	float					delta_x;
	float					delta_y;
	float					gradient;
	float					y;
}							t_xiaolin_wu;


t_list				*read_file(const char *filepath, t_file *file);
void				parser(t_list *list, int *data);

int					key_hook(int keycode, t_mlx *mlx);
void				free_data(t_mlx *mlx);
void				throw_error(int error_code);
t_file				*load_file(const char *file);
void				render(t_mlx *mlx);
void				draw_lines(t_vector3d *p, t_mlx *mlx);
void				bresenham_line(t_vector3d p0, t_vector3d p1, t_mlx *mlx);
//void				put_pixel(t_mlx *mlx, t_vector2d coord, float b, int c);
void				put_pixel(t_mlx *mlx, int x, int y, int color);
void				scale_z(t_mlx *mlx);

int					brightness(int color, float b);
void				xiaoline_wu_line(t_vector2d a, t_vector2d b, t_mlx *mlx);
void				isometric_view(t_vector3d *p, t_mlx *mlx);
void				parallel_view(t_vector3d *coord);
void				line(int x0, int y0, int x1, int y1, t_mlx *mlx);

void				memdel_size(t_list **list);
#endif
