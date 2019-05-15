/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:36:12 by judrion           #+#    #+#             */
/*   Updated: 2018/10/12 18:16:25 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*end_string;

	end_string = ft_strchr(s, '\0');
	if ((unsigned char)c == '\0')
		return (end_string);
	while (end_string >= s)
	{
		if (*(end_string) == (unsigned char)c)
			return (end_string);
		end_string--;
	}
	return (NULL);
}
