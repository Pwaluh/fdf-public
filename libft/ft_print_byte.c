/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_byte.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:52:48 by judrion           #+#    #+#             */
/*   Updated: 2018/11/23 11:45:29 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_byte(void *c, size_t nb_byte)
{
	size_t	i;

	i = 0;
	while (i < (8 * nb_byte))
	{
		if (i % 8 == 0 && i > 0)
			ft_putstr("   ");
		else if (i % 4 == 0 && i > 0)
			ft_putchar(' ');
		if ((*(unsigned long*)c >> (((8 * nb_byte) - 1) - i)) % 2 == 1)
			ft_putchar('1');
		else
			ft_putchar('0');
		i = i + 1;
	}
}
