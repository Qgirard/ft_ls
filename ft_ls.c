/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:52:02 by qgirard           #+#    #+#             */
/*   Updated: 2019/06/20 05:39:46 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls(t_info *stock, t_elem **infos)
{
	t_elem	*tmp;

	tmp = (*infos);
	if (stock->r)
	{
		while (tmp && tmp->next)
			tmp = tmp->next;
	}
	while (tmp)
	{
		if (stock->a == 0 && stock->majr == 0 && stock->l == 0)
			a_option(&tmp, 0);
		else if (stock->l)
			l_option(stock, &tmp);
		else if (stock->a)
			a_option(&tmp, 1);
		tmp = (stock->r) ? tmp->prev : tmp->next;
	}
	return (1);
}
