/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:56:26 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/14 18:32:26 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		majexception(char **str, t_check **stock, va_list vl, t_excep **current)
{
	if ((*stock)->type == 'D')
		(*stock)->bigdecimal = va_arg(vl, long);
	else if ((*stock)->type == 'U')
		*str = ft_strjoinf(*str, ft_ultoa_base(va_arg(vl, unsigned long),
		10), 3);
	else if ((*stock)->type == 'O')
		*str = ft_strjoinf(*str, ft_ultoa_base(va_arg(vl, unsigned long),
		8), 3);
	if (!*str)
		return (0);
	return (checksignerror(str, stock, vl, current));
}

int		exception(char **str, t_check **stock, va_list vl, t_excep **current)
{
	(*stock)->checkex = 0;
	if ((*stock)->type == 0)
		(*stock)->width--;
	if ((*stock)->type == 'c')
	{
		(*stock)->prec = -1;
		if ((*stock)->charzero == 0 || (*stock)->charzero == 256)
		{
			(*stock)->checkex = 1;
			if (!lists(str, stock, current))
				return (lastfree(str, stock, current, 0));
			(*stock)->ex = ((*stock)->ex) ? (*stock)->ex + 1 : 1;
			if (!(*str = ft_strjoinf(*str, "^@", 1)))
				return (0);
		}
		else
			*str = ft_strjoinf(*str, ft_tochartostr((*stock)->charzero), 3);
	}
	if ((*stock)->prec != -1 && (*stock)->prec < (*stock)->width
	&& (*stock)->zero == '0' && (*stock)->type != 's')
		(*stock)->zero = 0;
	return (convert0precision(str, stock, vl));
}
