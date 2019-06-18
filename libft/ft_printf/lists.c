/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:28:52 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/14 18:33:01 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		lists(char **str, t_check **stock, t_excep **current)
{
	t_excep	*tmp;
	t_excep *new;

	tmp = (*current);
	if ((*current) != NULL)
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	if (!(new = (t_excep *)malloc(sizeof(t_excep))))
		return (0);
	new->x = ((*stock)->width && (*stock)->less == 0)
	? ft_strlen(*str) + (*stock)->width - 1 : ft_strlen(*str);
	new->next = NULL;
	if (!(*current))
		(*current) = new;
	else
		tmp->next = new;
	return (1);
}
