/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8_decode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:31:49 by judrion           #+#    #+#             */
/*   Updated: 2018/11/21 19:10:36 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_utf8_decode(char *utf8)
{
	unsigned int	c;
	char			i;
	char			utf8_encode_size;

	c = 0;
	i = 1;
	if ((utf8_encode_size = ft_strlen(utf8)) == 1)
		return (*utf8 & 0x7F);
	if (utf8_encode_size == 2)
		c = *utf8 & 0x1F;
	else if (utf8_encode_size == 3)
		c = *utf8 & 0x0F;
	else if (utf8_encode_size == 4)
		c = *utf8 & 0x07;
	while (*(utf8 + i))
	{
		c = (c << 6) + (*(utf8 + i) & 0x3F);
		i = i + 1;
	}
	if (c >= 0xD800 && c <= 0xDFFFF)
		return (0);
	return (c);
}
