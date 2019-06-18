/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertinstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:12:29 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/14 18:22:49 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convertinstrwint(char **str, t_check **stock, va_list vl,
		t_excep **current)
{
	if ((*stock)->type == 'd')
		(*stock)->decimal = va_arg(vl, int);
	else if ((*stock)->type == 'u')
		*str = ft_strjoinf(*str, ft_utoa_base(va_arg(vl, unsigned int),
		10), 3);
	else if ((*stock)->type == 'b')
		*str = ft_strjoinf(*str, ft_utoa_base(va_arg(vl, unsigned int),
		2), 3);
	else if ((*stock)->type == 'c')
		(*stock)->charzero = va_arg(vl, int);
	else if ((*stock)->type == 's' && (*stock)->prec == -1)
		*str = ft_strjoinf(*str, va_arg(vl, char *), 1);
	else if ((*stock)->type == 'p')
		*str = ft_strjoinf(*str, ft_ultoa_base(va_arg(vl, unsigned long),
		16), 3);
	else if ((*stock)->type == 'o')
		*str = ft_strjoinf(*str, ft_utoa_base(va_arg(vl, unsigned int), 8), 3);
	else if ((*stock)->type == 'x')
		*str = ft_strjoinf(*str, ft_utoa_base(va_arg(vl, unsigned int), 16), 3);
	else if ((*stock)->type == 'X')
		*str = ft_strjoinf(*str,
		ft_toupperstr(ft_utoa_base(va_arg(vl, unsigned int), 16)), 3);
	if (!*str)
		return (0);
	return (checksignerror(str, stock, vl, current));
}

int		convertinstrwoptions(char **str, t_check **stock, va_list vl,
		t_excep **current)
{
	(*stock)->charzero = 1;
	if ((*stock)->diez == '#' || (*stock)->type == 'p')
	{
		if ((*stock)->type == 'x' || (*stock)->type == 'p')
			*str = ft_strjoinf(*str, "0x", 1);
		else if ((*stock)->type == 'X')
			*str = ft_strjoinf(*str, "0X", 1);
		else if ((*stock)->type == 'o' || (*stock)->type == 'O')
			*str = ft_strjoinf(*str, "0", 1);
		if (!*str)
			return (0);
	}
	if ((*stock)->size == NULL && (*stock)->type != 'U'
	&& (*stock)->type != 'f' && (*stock)->type != 'O' && (*stock)->type != 'D')
		return (convertinstrwint(str, stock, vl, current));
	else if ((*stock)->size != NULL || (*stock)->type == 'U'
	|| (*stock)->type == 'D' || (*stock)->type == 'O')
		return (convertinstrwsize(str, stock, vl, current));
	else if ((*stock)->type == 'f')
		return (convertfloats(str, stock, vl));
	return (1);
}

int		convertinstr(char **str, t_check **stock, va_list vl, t_excep **current)
{
	(*stock)->lenstr = ft_strlen(*str);
	if ((*stock)->type == 0)
		(*stock)->prec = -1;
	if ((*stock)->type == 'p' || (*stock)->type == 'c')
	{
		ft_strdel(&(*stock)->size);
		(*stock)->size = NULL;
	}
	if ((*stock)->type == '%')
	{
		if (!(*str = ft_strjoinf(*str, "%", 1)))
			return (0);
		(*stock)->prec = -1;
	}
	else if ((*stock)->plus == '+' && ((*stock)->type == 'd'
	|| (*stock)->type == 'D'))
	{
		if (!(*str = ft_strjoinf(*str, "+", 1)))
			return (0);
	}
	else if ((*stock)->space == ' ' && ((*stock)->type == 'd'
	|| (*stock)->type == 'D'))
		if (!(*str = ft_strjoinf(*str, " ", 1)))
			return (0);
	return (convertinstrwoptions(str, stock, vl, current));
}
