/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:58:14 by judrion           #+#    #+#             */
/*   Updated: 2018/12/10 17:56:37 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_setup_line(char *stock_rest)
{
	char			*current_read;
	int				ret_cmp;

	ret_cmp = 0;
	if (stock_rest != NULL && ((ret_cmp = ft_strcmp(stock_rest, "")) != 0))
	{
		current_read = ft_strdup(stock_rest);
		ft_strdel(&stock_rest);
	}
	else
	{
		if (ret_cmp == 0)
			ft_strdel(&stock_rest);
		current_read = ft_strnew(0);
	}
	return (current_read);
}

static int		ft_read(const int fd, char **stock_rest)
{
	char			*current_read;
	char			*new_line;
	char			*to_free;
	char			buffer[BUFF_SIZE + 1];
	ssize_t			byte_read;

	new_line = NULL;
	byte_read = BUFF_SIZE;
	if ((current_read = ft_setup_line(*stock_rest)) == NULL)
		return (-1);
	while (new_line == NULL && (byte_read = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (byte_read == -1)
			return (-1);
		buffer[byte_read] = '\0';
		to_free = current_read;
		if ((current_read = ft_strjoin(current_read, buffer)) == NULL)
			return (-1);
		ft_strdel(&to_free);
		new_line = ft_strchr(current_read, '\n');
	}
	if ((*stock_rest = ft_strdup(current_read)) == NULL)
		return (-1);
	ft_strdel(&current_read);
	return (byte_read);
}

static char		*ft_check_rest(char *stock_rest)
{
	char			*new_line;

	new_line = NULL;
	if (stock_rest != NULL)
		new_line = ft_strchr(stock_rest, '\n');
	return (new_line);
}

static int		ft_extract_line(char **stock, char **line, char *new_line, \
								int no_newline)
{
	char			*to_free;

	if (no_newline == 1)
	{
		to_free = *stock;
		*new_line = '\0';
		if ((*line = ft_strdup(*stock)) == NULL)
			return (-1);
		if ((*stock = ft_strdup(new_line + 1)) == NULL)
			return (-1);
		ft_strdel(&to_free);
	}
	else
	{
		if ((*line = ft_strdup(*stock)) == NULL)
			return (-1);
		ft_strdel(stock);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*file[OPEN_MAX + 1];
	int				ret_read;
	char			*new_line;

	if (fd < 0 || line == NULL || fd > OPEN_MAX)
		return (-1);
	if ((new_line = ft_check_rest(file[fd])) == NULL)
	{
		if ((ret_read = ft_read(fd, &file[fd])) == 0)
		{
			if (ft_strcmp(file[fd], "\0") != 0)
				return (ft_extract_line(&file[fd], line, NULL, 0));
			return (0);
		}
		else if (ret_read == -1)
			return (-1);
		new_line = ft_check_rest(file[fd]);
	}
	if (ft_extract_line(&file[fd], line, new_line, 1) == -1)
		return (-1);
	return (1);
}
