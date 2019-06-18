/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:07:57 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/01 17:07:16 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		freerror(char **str, t_check **stock, va_list vl, int i)
{
	if (*str)
		ft_strdel(str);
	if ((*stock)->size)
		ft_strdel(&(*stock)->size);
	free(*stock);
	va_end(vl);
	return (i);
}

int		lastfree(char **str, t_check **stock, t_excep **current, int i)
{
	t_excep	*tmp;

	if ((*stock)->colour)
		write(1, "\033[0m", 4);
	if (*str)
		ft_strdel(str);
	if ((*stock)->size)
		ft_strdel(&(*stock)->size);
	free(*stock);
	while ((*current))
	{
		tmp = (*current);
		(*current)->x = 0;
		(*current) = (*current)->next;
		free(tmp);
	}
	return (i);
}
