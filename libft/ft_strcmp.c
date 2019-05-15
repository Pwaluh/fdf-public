/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 14:16:21 by judrion           #+#    #+#             */
/*   Updated: 2018/10/12 14:28:04 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t		s1_length;
	size_t		s2_length;

	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	if (s1_length >= s2_length)
		return (ft_memcmp(s1, s2, s1_length));
	else
		return (ft_memcmp(s1, s2, s2_length));
}
