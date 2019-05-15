/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:56:30 by judrion           #+#    #+#             */
/*   Updated: 2019/05/15 15:07:00 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				main(int argc, char **argv)
{
	t_file		*map;
	t_mlx		*mlx;

	if (argc != 2)
		throw_error(USAGE);
	if ((mlx = init_mlx() == NULL)
			throw_error(MLX_ERROR);
	if ((map = load_file(argv[1])) == NULL)
		throw_error(MAP_ERROR);
	print(mlx, map);
	free_data(mlx, map);
	return (0);
}
