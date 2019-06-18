/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkoptions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:01:18 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/14 18:22:02 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	checkwidthstar(t_check **stock, va_list vl)
{
	(*stock)->width = va_arg(vl, int);
	if ((*stock)->width < 0)
	{
		(*stock)->less = '-';
		(*stock)->width = (*stock)->width * -1;
	}
}

int		checkwidth(const char **format, t_check **stock, va_list vl)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = ft_strnew(0)))
		return (0);
	if ((*format)[0] == '*')
		checkwidthstar(stock, vl);
	while (ft_isdigit((*format)[i]) == 1)
	{
		if (!(tmp = ft_strjoinf(tmp, (char *)&(*format)[i], 1)))
		{
			ft_strdel(&tmp);
			return (0);
		}
		i++;
	}
	if (i > 0)
		(*stock)->width = ft_atoi(tmp);
	else if ((*format)[0] != '*')
		(*stock)->width = 0;
	*format = ((*format)[0] == '*') ? *format + 1 : *format + i;
	ft_strdel(&tmp);
	return (checkprecision(format, stock));
}

void	checkoptions2(const char **format, t_check **stock)
{
	if ((*format)[1] == '#')
		(*stock)->diez = '#';
	else if ((*format)[1] == '0')
		(*stock)->zero = '0';
	else if ((*format)[1] == '-')
		(*stock)->less = '-';
	else if ((*format)[1] == '+')
	{
		(*stock)->plus = '+';
		while ((*format)[2] == '+')
			*format = *format + 1;
	}
	else if ((*format)[1] == ' ')
	{
		(*stock)->space = ' ';
		while ((*format)[2] == ' ')
			*format = *format + 1;
	}
}

int		checkoptions(const char **format, t_check **stock, va_list vl)
{
	(*stock)->diez = 0;
	(*stock)->zero = 0;
	(*stock)->plus = 0;
	(*stock)->less = 0;
	(*stock)->space = 0;
	while (((*format)[1] == '#' || (*format)[1] == '0' || (*format)[1] == '-'
	|| (*format)[1] == '+' || (*format)[1] == ' '))
	{
		checkoptions2(format, stock);
		*format = *format + 1;
	}
	if ((*stock)->less == '-')
		(*stock)->zero = 0;
	if ((*stock)->plus == '+')
		(*stock)->space = 0;
	*format = *format + 1;
	return (checkwidth(format, stock, vl));
}
