/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_elems.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:38:39 by qgirard           #+#    #+#             */
/*   Updated: 2019/06/13 06:07:04 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		free_elems(t_elem **infos)
{
	t_elem	*tmp;

	while (*infos)
	{
		tmp = (*infos);
		if (tmp->name)
			ft_strdel(&(tmp->name));
		if (tmp->name_dir)
			ft_strdel(&(tmp->name_dir));
		(*infos) = (*infos)->next;
		if (tmp)
			free(tmp);
	}
	return (1);
}
