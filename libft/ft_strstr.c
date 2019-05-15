/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:42:17 by judrion           #+#    #+#             */
/*   Updated: 2018/10/18 16:40:41 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (*(needle) == '\0')
		return ((char *)haystack);
	while (*(haystack + i))
	{
		j = 0;
		if (*(haystack + i) == *(needle))
		{
			while (*(needle + j) && *(haystack + i + j) == *(needle + j))
				j = j + 1;
			if (*(needle + j) == '\0')
				return ((char *)(haystack + i));
		}
		i = i + 1;
	}
	return (NULL);
}
