/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:48:59 by judrion           #+#    #+#             */
/*   Updated: 2018/10/12 18:04:01 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (*(needle) == '\0')
		return ((char *)haystack);
	while (*(haystack + i) && i < len)
	{
		j = 0;
		if (*(haystack + i) == *(needle))
		{
			while (*(needle + j) && *(haystack + i + j) == *(needle + j) \
					&& j + i < len)
				j = j + 1;
			if (*(needle + j) == '\0')
				return ((char *)(haystack + i));
		}
		i = i + 1;
	}
	return (NULL);
}
