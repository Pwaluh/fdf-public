/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 00:04:40 by judrion           #+#    #+#             */
/*   Updated: 2018/10/15 00:13:43 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	max_len;

	str = NULL;
	if (s1 != NULL && s2 != NULL)
	{
		max_len = ft_strlen(s1) + ft_strlen(s2);
		str = (char *)malloc(sizeof(char) + max_len + 1);
		if (str == NULL)
			return (str);
		ft_bzero(str, max_len + 1);
		ft_strcpy(str, s1);
		ft_strcpy(str + ft_strlen(s1), s2);
	}
	return (str);
}
