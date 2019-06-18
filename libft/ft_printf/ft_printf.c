/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:11:40 by qgirard           #+#    #+#             */
/*   Updated: 2019/04/08 16:54:15 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		applycolours(const char **format, char **str, t_check **stock)
{
	if (!ft_strncmp(*format, "{red}", 5))
		*str = ft_strjoinf(*str, "\033[31m", 1);
	else if (!ft_strncmp(*format, "{eoc}", 5))
		*str = ft_strjoinf(*str, "\033[0m", 1);
	else if (!ft_strncmp(*format, "{green}", 7))
		*str = ft_strjoinf(*str, "\033[32m", 1);
	else if (!ft_strncmp(*format, "{yellow}", 8))
		*str = ft_strjoinf(*str, "\033[33m", 1);
	else if (!ft_strncmp(*format, "{blue}", 6))
		*str = ft_strjoinf(*str, "\033[34m", 1);
	else if (!ft_strncmp(*format, "{rose}", 6))
		*str = ft_strjoinf(*str, "\033[35m", 1);
	else if (!ft_strncmp(*format, "{cyan}", 6))
		*str = ft_strjoinf(*str, "\033[36m", 1);
	if (!*str)
		return (0);
	(*stock)->colour = 1;
	return (1);
}

int		checkcolours(const char **format, char **str, t_check **stock)
{
	if (!(*str = ft_strjoinf(*str, ft_strsub(*format, 0,
	ft_strlen(*format) - ft_strlen(ft_strchr(*format, '{'))), 3)))
		return (0);
	*format = ft_strchr(*format, '{');
	if (!ft_strncmp(*format, "{red}", 5) || !ft_strncmp(*format, "{eoc}", 5)
	|| !ft_strncmp(*format, "{green}", 7) || !ft_strncmp(*format, "{yellow}", 8)
	|| !ft_strncmp(*format, "{blue}", 6) || !ft_strncmp(*format, "{rose}", 6)
	|| !ft_strncmp(*format, "{cyan}", 6))
	{
		if (!applycolours(format, str, stock))
			return (0);
		*format = ft_strchr(*format, '}') + 1;
	}
	else
		*format = *format + 1;
	return (1);
}

int		checkpercent(const char **format, char **str, t_check **stock)
{
	if (ft_strchr(*format, '{') && ft_strchr(*format, '{')[1] != '%')
	{
		if (!checkcolours(format, str, stock))
			return (0);
		checkpercent(format, str, stock);
	}
	else if (ft_strchr(*format, '%'))
	{
		if (!((*str) = ft_strjoinf(*str, ft_strsub(*format, 0,
		ft_strlen(*format) - ft_strlen(ft_strchr(*format, '%'))), 3)))
			return (0);
		*format = ft_strchr(*format, '%');
	}
	else
	{
		if (!((*str) = ft_strjoinf(*str, ft_strsub(*format, 0,
		ft_strlen(*format)), 3)))
			return (0);
		return (0);
	}
	return (1);
}

int		printend(char **str, t_check **stock, t_excep **current)
{
	int		i;
	t_excep *tmp;

	i = 0;
	tmp = (*current);
	if ((*stock)->ex == 0)
		ft_putstr(*str);
	else
	{
		while (tmp)
		{
			while (i < tmp->x)
			{
				ft_putchar((*str)[i]);
				i++;
			}
			write(1, "\0", 1);
			i = i + 2;
			tmp = tmp->next;
		}
		while ((*str)[i])
			ft_putchar((*str)[i++]);
	}
	i = ((*stock)->ex > 0) ? ft_strlen(*str) - (*stock)->ex : ft_strlen(*str);
	return (lastfree(str, stock, current, i));
}

int		ft_printf(const char *format, ...)
{
	va_list	vl;
	t_excep	*current;
	char	*str;
	t_check *stock;

	if (!(stock = (t_check *)malloc(sizeof(t_check))))
		return (0);
	current = NULL;
	stock->colour = 0;
	stock->size = NULL;
	stock->ex = 0;
	va_start(vl, format);
	if (!(str = ft_strnew(0)))
		return (0);
	while (checkpercent(&format, &str, &stock))
	{
		if (!checkoptions(&format, &stock, vl))
			return (freerror(&str, &stock, vl, -1));
		if (!convertinstr(&str, &stock, vl, &current))
			return (freerror(&str, &stock, vl, -1));
		ft_strdel(&stock->size);
	}
	va_end(vl);
	return (printend(&str, &stock, &current));
}
