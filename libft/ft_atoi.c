/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 14:52:22 by judrion           #+#    #+#             */
/*   Updated: 2018/11/28 17:17:21 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t						i;
	char						sign;
	unsigned long long			result;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_iswhitespace(*(str + i)))
		i = i + 1;
	sign = *(str + i) == '-' ? -1 : 1;
	if (*(str + i) == '+' || *(str + i) == '-')
		i = i + 1;
	while (ft_isdigit(*(str + i)))
	{
		result = result * 10 + *(str + i) - '0';
		if (result > MAX_ULLONG)
			return (sign == -1 ? 0 : -1);
		i = i + 1;
	}
	return ((int)result * sign);
}
