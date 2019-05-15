/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 23:48:38 by judrion           #+#    #+#             */
/*   Updated: 2018/10/14 23:50:23 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*str;
	size_t			s_len;
	unsigned int	i;

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
			*(str + i) = f(i, *(s + i));
			i = i + 1;
		}
	}
	return (str);
}
