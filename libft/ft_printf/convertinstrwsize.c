/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertinstrwsize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:00:18 by qgirard           #+#    #+#             */
/*   Updated: 2019/01/31 16:53:58 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convertinstrwsizehh(char **str, t_check **stock, va_list vl,
		t_excep **current)
{
	if ((*stock)->type == 'd')
		*str = ft_strjoinf(*str, ft_sctoa((*stock)->sshort), 3);
	else if ((*stock)->type == 'u')
		*str = ft_strjoinf(*str, ft_uctoa_base((*stock)->sshort, 10), 3);
	else if ((*stock)->type == 'b')
		*str = ft_strjoinf(*str, ft_uctoa_base((*stock)->sshort, 2), 3);
	else if ((*stock)->type == 'o')
		*str = ft_strjoinf(*str, ft_uctoa_base((*stock)->sshort, 8), 3);
	else if ((*stock)->type == 'x')
		*str = ft_strjoinf(*str, ft_uctoa_base((*stock)->sshort, 16), 3);
	else if ((*stock)->type == 'X')
		*str = ft_strjoinf(*str,
		ft_toupperstr(ft_uctoa_base((*stock)->sshort, 16)), 3);
	if (!*str)
		return (0);
	return (checksignerror(str, stock, vl, current));
}

int		convertinstrwsizeh(char **str, t_check **stock, va_list vl,
		t_excep **current)
{
	(*stock)->sshort = va_arg(vl, int);
	if (ft_strcmp((*stock)->size, "h"))
		return (convertinstrwsizehh(str, stock, vl, current));
	else if ((*stock)->type == 'd')
		*str = ft_strjoinf(*str, ft_stoa((*stock)->sshort), 3);
	else if ((*stock)->type == 'u')
		*str = ft_strjoinf(*str, ft_ustoa_base((*stock)->sshort, 10), 3);
	else if ((*stock)->type == 'b')
		*str = ft_strjoinf(*str, ft_ustoa_base((*stock)->sshort, 2), 3);
	else if ((*stock)->type == 'o')
		*str = ft_strjoinf(*str, ft_ustoa_base((*stock)->sshort, 8), 3);
	else if ((*stock)->type == 'x')
		*str = ft_strjoinf(*str, ft_ustoa_base((*stock)->sshort, 16), 3);
	else if ((*stock)->type == 'X')
		*str = ft_strjoinf(*str,
		ft_toupperstr(ft_ustoa_base((*stock)->sshort, 16)), 3);
	if (!*str)
		return (0);
	return (checksignerror(str, stock, vl, current));
}

int		convertinstrwsizell(char **str, t_check **stock, va_list vl,
		t_excep **current)
{
	if (ft_strcmp((*stock)->size, "ll"))
		return (convertinstrwsizeh(str, stock, vl, current));
	else if ((*stock)->type == 'd')
		*str = ft_strjoinf(*str, ft_ltoa(va_arg(vl, long long)), 3);
	else if ((*stock)->type == 'u')
		*str = ft_strjoinf(*str, ft_ultoa_base(va_arg(vl,
		unsigned long long), 10), 3);
	else if ((*stock)->type == 'b')
		*str = ft_strjoinf(*str, ft_ultoa_base(va_arg(vl,
		unsigned long long), 2), 3);
	else if ((*stock)->type == 'o')
		*str = ft_strjoinf(*str, ft_ultoa_base(va_arg(vl,
		unsigned long long), 8), 3);
	else if ((*stock)->type == 'x')
		*str = ft_strjoinf(*str, ft_ultoa_base(va_arg(vl,
		unsigned long long), 16), 3);
	else if ((*stock)->type == 'X')
		*str = ft_strjoinf(*str,
		ft_toupperstr(ft_ultoa_base(va_arg(vl, unsigned long long), 16)), 3);
	if (!*str)
		return (0);
	return (checksignerror(str, stock, vl, current));
}

int		convertinstrwsize(char **str, t_check **stock, va_list vl,
		t_excep **current)
{
	if ((*stock)->type == 'U' || (*stock)->type == 'D' || (*stock)->type == 'O')
		return (majexception(str, stock, vl, current));
	else if (ft_strcmp((*stock)->size, "l"))
		return (convertinstrwsizell(str, stock, vl, current));
	else if ((*stock)->type == 'd')
		*str = ft_strjoinf(*str, ft_ltoa(va_arg(vl, long)), 3);
	else if ((*stock)->type == 'u')
		*str = ft_strjoinf(*str, ft_ultoa_base(va_arg(vl, unsigned long),
		10), 3);
	else if ((*stock)->type == 'b')
		*str = ft_strjoinf(*str, ft_ultoa_base(va_arg(vl, unsigned long),
		2), 3);
	else if ((*stock)->type == 'o')
		*str = ft_strjoinf(*str, ft_ultoa_base(va_arg(vl, unsigned long),
		8), 3);
	else if ((*stock)->type == 'x')
		*str = ft_strjoinf(*str, ft_ultoa_base(va_arg(vl, unsigned long),
		16), 3);
	else if ((*stock)->type == 'X')
		*str = ft_strjoinf(*str,
		ft_toupperstr(ft_ultoa_base(va_arg(vl, unsigned long), 16)), 3);
	if (!*str)
		return (0);
	return (checksignerror(str, stock, vl, current));
}
