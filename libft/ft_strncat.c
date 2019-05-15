/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 19:14:03 by judrion           #+#    #+#             */
/*   Updated: 2018/11/13 22:16:08 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, char *s2, size_t n)
{
	char	*end_s1;
	size_t	size_s2;

	end_s1 = ft_strchr(s1, '\0');
	size_s2 = ft_strchr(s2, '\0') - s2;
	if (size_s2 >= n)
		*(end_s1 + n) = '\0';
	else
		*(end_s1 + size_s2) = '\0';
	ft_memccpy(end_s1, s2, '\0', n);
	return (s1);
}
