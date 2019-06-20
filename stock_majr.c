/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_majr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 22:59:10 by qgirard           #+#    #+#             */
/*   Updated: 2019/06/21 00:17:38 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		stock_majr(t_elem **infos, t_info *stock)
{
	t_elem	*tmp;
	char	*buf;

	tmp = (*infos);
	buf = NULL;
	while (tmp)
	{
		if (tmp->type == 4 && ft_strcmp(".", tmp->name)
		&& ft_strcmp("..", tmp->name))
		{
			buf = (tmp->name_dir) ? ft_strjoin(tmp->name_dir, "/")
			: ft_strjoin(".", "/");
			buf = ft_strjoinf(buf, tmp->name, 1);
			if (stock->a)
				if (!list_with_name(infos, buf, 1, 2))
					return (0);
			if (!stock->a)
				if (!list_with_name(infos, buf, 0, 2))
					return (0);
			ft_strdel(&buf);
		}
		tmp = tmp->next;
	}
	return (1);
}
