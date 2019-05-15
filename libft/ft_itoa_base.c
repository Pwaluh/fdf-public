/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:41:34 by judrion           #+#    #+#             */
/*   Updated: 2018/11/28 18:20:06 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_construct_base(char base)
{
	char	*str_base;
	char	i;

	str_base = ft_memalloc(base);
	i = 0;
	while (i < base)
	{
		if (i < 10)
			*(str_base + i) = '0' + i;
		else
			*(str_base + i) = i - 10 + 'A';
		i = i + 1;
	}
	return (str_base);
}

static int		ft_sign(int *n)
{
	if (*n < 0)
	{
		*n = *n * -1;
		return (-1);
	}
	else
		return (1);
}

static int		ft_count_digit(int n, int base)
{
	int		nb_digit;

	nb_digit = 1;
	while (n > 0)
	{
		nb_digit = nb_digit + 1;
		n = n / base;
	}
	return (nb_digit);
}

static char		*ft_construct_string(int n, int base, char *str)
{
	char	*str_base;
	size_t	i;

	i = 0;
	str_base = NULL;
	if (base > 0 && base <= 16)
		str_base = ft_construct_base(base);
	while (n > 0)
	{
		*(str + i) = *(str_base + (n % base));
		n = n / base;
		i = i + 1;
	}
	ft_memdel((void*)&str_base);
	return (str);
}

char			*ft_itoa_base(int n, char base)
{
	char	*str;
	int		sign;

	str = NULL;
	sign = ft_sign(&n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == MIN_INT)
		return (ft_strdup("-2147483648"));
	if (sign == -1 && base == 10)
	{
		if ((str = ft_memalloc(ft_count_digit(n, base))) == NULL)
			return (NULL);
		*str = '-';
		ft_construct_string(n, base, str + 1);
		ft_strrev(str + 1);
	}
	else
	{
		str = ft_memalloc(ft_count_digit(n, base));
		ft_construct_string(n, base, str);
		ft_strrev(str);
	}
	return (str);
}
