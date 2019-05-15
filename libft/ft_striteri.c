/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 23:33:42 by judrion           #+#    #+#             */
/*   Updated: 2018/11/13 22:26:00 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	size_t			s_length;

	if (s != NULL && f != NULL)
	{
		i = 0;
		s_length = ft_strlen(s);
		while (i < s_length)
		{
			f(i, s + i);
			i = i + 1;
		}
	}
}
