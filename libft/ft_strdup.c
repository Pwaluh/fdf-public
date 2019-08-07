/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 17:38:04 by judrion           #+#    #+#             */
/*   Updated: 2019/08/07 16:24:36 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	src_size;

	src_size = ft_strlen(s1);
	dest = (char*)ft_memalloc(sizeof(char*) * (src_size + 1));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s1, src_size);
	dest[src_size + 1] = '\0';
	return (dest);
}
