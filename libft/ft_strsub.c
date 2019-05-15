/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 23:58:19 by judrion           #+#    #+#             */
/*   Updated: 2018/10/15 00:02:24 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*str;

	str = NULL;
	if (s != NULL)
	{
		str = (char*)malloc(sizeof(char) + len);
		if (str == NULL)
			return (str);
		*(str + len) = '\0';
		ft_memcpy(str, s + start, len);
	}
	return (str);
}
