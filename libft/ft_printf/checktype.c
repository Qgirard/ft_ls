/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checktype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:53:34 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/04 10:32:08 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		checktype(const char **format, t_check **stock)
{
	if ((*format)[0] == 'c' || (*format)[0] == 'C')
		(*stock)->type = 'c';
	else if ((*format)[0] == 's')
		(*stock)->type = 's';
	else if ((*format)[0] == 'p')
		(*stock)->type = 'p';
	else if ((*format)[0] == 'd' || (*format)[0] == 'D' || (*format)[0] == 'i')
		(*stock)->type = ((*format)[0] == 'D') ? 'D' : 'd';
	else if ((*format)[0] == 'o' || (*format)[0] == 'O')
		(*stock)->type = ((*format)[0] == 'o') ? 'o' : 'O';
	else if ((*format)[0] == 'u' || (*format)[0] == 'U')
		(*stock)->type = ((*format)[0] == 'u') ? 'u' : 'U';
	else if ((*format)[0] == 'x' || (*format)[0] == 'X')
		(*stock)->type = ((*format)[0] == 'x') ? 'x' : 'X';
	else if ((*format)[0] == 'f' || (*format)[0] == 'F')
		(*stock)->type = 'f';
	else if ((*format)[0] == '%' || (*format)[0] == 'b')
		(*stock)->type = ((*format)[0] == '%') ? '%' : 'b';
	else
		(*stock)->type = 0;
	if ((*stock)->type != 0)
		*format = *format + 1;
	return (1);
}

int		checklittlesize(const char **format, t_check **stock)
{
	if ((*format)[0] == 'h')
	{
		if ((*format)[1] == 'h')
		{
			if (!((*stock)->size = ft_strdup("hh")))
				return (0);
		}
		else
		{
			if (!((*stock)->size = ft_strdup("h")))
				return (0);
		}
		*format = *format + ft_strlen((*stock)->size);
	}
	else if ((*format)[0] == 'L')
	{
		if (!((*stock)->size = ft_strdup("L")))
			return (0);
		*format = *format + 1;
	}
	return (checktype(format, stock));
}

int		checksize(const char **format, t_check **stock)
{
	if ((*format)[0] == 'l' || (*format)[0] == 'j' || (*format)[0] == 'z')
	{
		if ((*format)[1] == 'l')
		{
			if (!((*stock)->size = ft_strdup("ll")))
				return (0);
		}
		else
		{
			if (!((*stock)->size = ft_strdup("l")))
				return (0);
		}
		*format = *format + ft_strlen((*stock)->size);
	}
	return (checklittlesize(format, stock));
}

int		checkprecision(const char **format, t_check **stock)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!(tmp = ft_strnew(0)))
		return (0);
	if ((*format)[i] == '.')
	{
		i++;
		while (ft_isdigit((*format)[i]) == 1)
		{
			if (!(tmp = ft_strjoinf(tmp, (char *)&(*format)[i], 1)))
			{
				ft_strdel(&tmp);
				return (0);
			}
			i++;
		}
		(*stock)->prec = ft_atoi(tmp);
		*format = *format + i;
	}
	else
		(*stock)->prec = -1;
	ft_strdel(&tmp);
	return (checksize(format, stock));
}
