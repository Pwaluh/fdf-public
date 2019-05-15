/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:44:44 by judrion           #+#    #+#             */
/*   Updated: 2018/11/21 17:50:57 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*current_element;

	if (lst != NULL && f != NULL)
	{
		current_element = lst;
		while (current_element != NULL)
		{
			f(current_element);
			current_element = current_element->next;
		}
	}
}
