/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memswap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 12:51:06 by judrion           #+#    #+#             */
/*   Updated: 2019/02/20 12:54:24 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	memswap(void *a, void *b, size_t size)
{
	void	*c;

	c = ft_memalloc(size);
	if (c != NULL)
	{
		ft_memcpy(c, a, size);
		ft_memcpy(a, b, size);
		ft_memcpy(b, c, size);
	}
	free(c);
}
