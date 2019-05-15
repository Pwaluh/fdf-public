/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 23:30:19 by judrion           #+#    #+#             */
/*   Updated: 2018/11/13 22:25:53 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t		s_size;
	size_t		i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		s_size = ft_strlen(s);
		while (i < s_size)
		{
			f(s + i);
			i = i + 1;
		}
	}
}
