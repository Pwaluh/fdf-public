/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:42:02 by judrion           #+#    #+#             */
/*   Updated: 2018/11/28 11:55:05 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd >= 0)
	{
		if (n == -2147483648)
			ft_putstr_fd("-2147483648", fd);
		else
		{
			if (n < 0)
			{
				ft_putchar_fd('-', fd);
				ft_putnbr_fd(n * -1, fd);
			}
			else
			{
				if (n >= 10)
					ft_putnbr_fd(n / 10, fd);
				ft_putchar_fd('0' + n % 10, fd);
			}
		}
	}
}
