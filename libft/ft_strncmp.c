/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 14:30:35 by judrion           #+#    #+#             */
/*   Updated: 2018/10/12 18:16:06 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		s1_length;
	size_t		s2_length;

	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	if (s1_length > n || s2_length > n)
		return (ft_memcmp(s1, s2, n));
	else
	{
		if (s1_length > s2_length)
			return (ft_memcmp(s1, s2, s1_length));
		return (ft_memcmp(s1, s2, s2_length));
	}
}
