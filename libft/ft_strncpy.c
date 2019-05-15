/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:01:28 by judrion           #+#    #+#             */
/*   Updated: 2018/10/10 18:21:20 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*src_end;
	size_t	cpy_size;

	src_end = ft_memccpy(dst, src, 0, len);
	cpy_size = src_end - dst;
	if (cpy_size != len && src_end != NULL)
		ft_bzero(src_end, len - cpy_size);
	return (dst);
}
