/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:27:33 by judrion           #+#    #+#             */
/*   Updated: 2018/11/23 11:41:48 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*element_to_del;

	if (del != NULL && *alst != NULL)
	{
		element_to_del = *alst;
		del(element_to_del->content, element_to_del->content_size);
		free(*alst);
		*alst = NULL;
	}
}
