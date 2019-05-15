/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 18:31:15 by judrion           #+#    #+#             */
/*   Updated: 2018/10/18 18:57:26 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	char	*s_end;
	char	c;
	char	*s_begin;

	s_begin = s;
	s_end = ft_strchr(s, '\0') - 1;
	while (s < s_end)
	{
		c = *s;
		*s = *s_end;
		*s_end = c;
		s++;
		s_end--;
	}
	return (s_begin);
}
