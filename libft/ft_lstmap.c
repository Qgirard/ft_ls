/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:31:34 by qgirard           #+#    #+#             */
/*   Updated: 2018/11/16 15:39:03 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*tmp;

	if (lst)
	{
		if (!(list = f(ft_lstnew(lst->content, lst->content_size))))
			return (NULL);
		tmp = list;
		lst = lst->next;
		while (lst != NULL)
		{
			if (!(list->next = f(ft_lstnew(lst->content, lst->content_size))))
				return (NULL);
			lst = lst->next;
			list = list->next;
		}
		return (tmp);
	}
	return (NULL);
}
