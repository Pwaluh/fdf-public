/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:03:28 by judrion           #+#    #+#             */
/*   Updated: 2018/11/13 19:28:24 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*element;

	element = (t_list*)ft_memalloc(sizeof(t_list));
	if (element == NULL)
		return (element);
	if (content == NULL)
	{
		element->content = NULL;
		element->content_size = 0;
	}
	else
	{
		element->content = ft_memalloc(content_size);
		if (element->content == NULL)
			return (NULL);
		ft_memcpy(element->content, content, content_size);
		element->content_size = content_size;
	}
	element->next = NULL;
	return (element);
}
