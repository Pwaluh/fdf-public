/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 00:13:51 by judrion           #+#    #+#             */
/*   Updated: 2018/10/18 16:25:13 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	size_t		i;
	char		*str;
	char		*s_end;

	str = NULL;
	if (s != NULL)
	{
		i = 0;
		while (*(s + i) == ' ' || *(s + i) == '\n' || *(s + i) == '\t')
			i = i + 1;
		s_end = ft_strchr(s, '\0') - 1;
		if (s_end + 1 == s + i)
			return (ft_memalloc(1));
		while (*s_end == ' ' || *s_end == '\t' || *s_end == '\n')
			s_end--;
		str = ft_memalloc((s_end + 1) - (s + i) + 1);
		if (str == NULL)
			return (str);
		ft_memcpy(str, (s + i), (s_end + 1) - (s + i));
	}
	return (str);
}
