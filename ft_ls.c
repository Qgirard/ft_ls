/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:52:02 by qgirard           #+#    #+#             */
/*   Updated: 2019/06/14 04:14:52 by qgirard          ###   ########.fr       */
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
	//if (stock->t)
	///	while (tmp->next)
		//	sort_time(infos);
	//if (stock->l)
	//	print_block(infos,stock);
	while (tmp)
	{
		if (stock->a == 0 && stock->majr == 0 && stock->l == 0)
			a_option(&tmp, 0);
	/*	else if (stock->l && stock->t)
		{
			sort_time(&tmp);
			l_option(stock, &tmp);
		}*/
		else if (stock->l)
		{
			// print_block(tmp->name);
			l_option(stock, &tmp);
		}
		//else if (stock->t)
		//	sort_time(&tmp);
		else if (stock->a)
			a_option(&tmp, 1);
		tmp = (stock->r) ? tmp->prev : tmp->next;
	}
	return (1);
}
