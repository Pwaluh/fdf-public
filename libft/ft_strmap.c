/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 23:39:41 by judrion           #+#    #+#             */
/*   Updated: 2018/10/15 00:04:01 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*str;
	size_t	s_len;
	size_t	i;

	i = 0;
	str = NULL;
	if (s != NULL)
	{
		s_len = ft_strlen(s);
		str = (char*)malloc(sizeof(char) * s_len + 1);
		if (str == NULL)
			return (str);
		*(str + s_len) = '\0';
		while (i < s_len)
		{
			*(str + i) = f(*(s + i));
			i = i + 1;
		}
	}
	return (str);
}
