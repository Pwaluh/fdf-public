/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:54:06 by judrion           #+#    #+#             */
/*   Updated: 2019/08/09 14:45:43 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE		4096
# include <limits.h>
# include <fcntl.h>
# include "libft.h"

int				get_next_line(const int fd, char **line);

#endif
