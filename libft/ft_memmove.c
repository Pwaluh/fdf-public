/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:33:10 by judrion           #+#    #+#             */
/*   Updated: 2018/11/13 22:21:10 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;

	i = 0;
	if (src < dst && (src + len) > dst)
	{
		while (len > 0)
		{
			*(unsigned char*)(dst + len - 1) = *(unsigned char*)(src + len - 1);
			len = len - 1;
		}
	}
	else if (dst < src && (dst + len) > src)
	{
		while (i < len)
		{
			*(unsigned char*)(dst + i) = *(unsigned char*)(src + i);
			i = i + 1;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
