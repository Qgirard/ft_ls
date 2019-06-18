/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:12:41 by qgirard           #+#    #+#             */
/*   Updated: 2018/11/16 13:56:37 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list **tmp;

	tmp = alst;
	while (*alst != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		(*alst) = (*alst)->next;
	}
	alst = tmp;
	ft_memdel((void **)alst);
}
