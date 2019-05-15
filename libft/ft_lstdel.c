/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:31:57 by judrion           #+#    #+#             */
/*   Updated: 2018/11/13 20:46:38 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current_element;
	t_list	*next_element;

	if (*alst != NULL && del != NULL)
	{
		current_element = *alst;
		while (current_element != NULL)
		{
			next_element = current_element->next;
			ft_lstdelone(&current_element, del);
			current_element = next_element;
		}
		*alst = NULL;
	}
}
