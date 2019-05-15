/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8_encode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:28:48 by judrion           #+#    #+#             */
/*   Updated: 2018/11/21 17:57:43 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		ft_count_byte(unsigned int c)
{
	if (c < 0x80)
		return (1);
	else if (c < 0x0800)
		return (2);
	else if (c < 0x10000)
	{
		if (c >= 0xD800 && c <= 0xDFFFF)
			return (-1);
		return (3);
	}
	else if (c <= 0x10FFFF)
		return (4);
	else
		return (-1);
}

static void		ft_encode(unsigned int c, char *utf8, char nb_byte)
{
	if (nb_byte == 1)
		*utf8 = (char)c;
	else if (nb_byte == 2)
	{
		*(utf8) = 0xC0 + ((c >> 6) & 0x1F);
		*(utf8 + 1) = 0x80 + (c & 0x3F);
	}
	else if (nb_byte == 3)
	{
		*(utf8) = 0xE0 + ((c >> 12) & 0xF);
		*(utf8 + 1) = 0x80 + ((c >> 6) & 0x3F);
		*(utf8 + 2) = 0x80 + (c & 0x3F);
	}
	else
	{
		*(utf8) = 0xF0 + ((c >> 18) & 0x7);
		*(utf8 + 1) = 0x80 + ((c >> 12) & 0x3F);
		*(utf8 + 2) = 0x80 + ((c >> 6) & 0x3F);
		*(utf8 + 3) = 0x80 + (c & 0x3F);
	}
}

char			*ft_utf8_encode(unsigned int c)
{
	char	*utf8_sequence;
	char	nb_byte;

	nb_byte = ft_count_byte(c);
	if (nb_byte == -1)
		return (NULL);
	utf8_sequence = (char*)ft_memalloc(sizeof(char) * nb_byte);
	if (utf8_sequence == NULL)
		return (NULL);
	ft_encode(c, utf8_sequence, nb_byte);
	return (utf8_sequence);
}
