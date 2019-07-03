/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stockinfos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:22:39 by qgirard           #+#    #+#             */
/*   Updated: 2019/06/12 23:55:14 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		stockinfos(t_info *stock, int i)
{
	if (i == 'l')
		stock->l = 1;
	else if (i == 'R')
		stock->majr = 1;
	else if (i == 'a')
		stock->a = 1;
	else if (i == 'r')
		stock->r = 1;
	else if (i == 't')
		stock->t = 1;
	else
	{
		ft_putendl("Invalid option");
		return (0);
	}
	return (1);
}
