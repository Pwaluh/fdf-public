/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 14:23:11 by judrion           #+#    #+#             */
/*   Updated: 2018/11/13 22:54:51 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*end_dst;
	char	*end_src;

	end_dst = ft_strchr(dst, '\0');
	if (ft_strlen(dst) >= size || size == 0)
		return (size + ft_strlen(src));
	end_src = ft_memccpy(end_dst, src, '\0', size - ft_strlen(dst) - 1);
	if (end_src)
		return (ft_strlen(dst));
	else
		*(end_dst + size - (end_dst - dst) - 1) = '\0';
	return ((end_dst - dst) + ft_strlen(src));
}
