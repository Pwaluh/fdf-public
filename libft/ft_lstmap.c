/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:55:35 by judrion           #+#    #+#             */
/*   Updated: 2018/11/13 21:10:49 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*mapped_lst;
	t_list	*mapped_lst_starting_point;
	t_list	*current_element;

	mapped_lst_starting_point = NULL;
	if (lst != NULL && f != NULL)
	{
		current_element = lst;
		mapped_lst = f(current_element);
		mapped_lst_starting_point = mapped_lst;
		current_element = current_element->next;
		while (current_element != NULL)
		{
			mapped_lst->next = f(current_element);
			mapped_lst = mapped_lst->next;
			current_element = current_element->next;
		}
	}
	return (mapped_lst_starting_point);
}
