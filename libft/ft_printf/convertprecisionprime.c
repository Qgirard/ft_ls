/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertprecisionprime.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:38:00 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/14 18:30:45 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convertprecisionwos(char **str, t_check **stock)
{
	char	*tmp;
	char	*ptr;
	int		i;

	i = 0;
	if (!(ptr = ft_reallocstr(NULL, (*stock)->prec - (*stock)->sizetype)))
		return (0);
	while (i < (*stock)->prec - (*stock)->sizetype)
		ptr[i++] = '0';
	i = ft_strlen(*str) - (*stock)->sizetype;
	if (!(tmp = ft_strsub(*str, i, (*stock)->sizetype)))
		return (convertprecisionerr(&tmp, &ptr, 2));
	while ((*str)[i])
		(*str)[i++] = '\0';
	if (!(*str = ft_strjoinf(*str, ptr, 3)))
		return (convertprecisionerr(&tmp, &ptr, 3));
	if (!(*str = ft_strjoinf(*str, tmp, 3)))
		return (convertprecisionerr(&tmp, &ptr, 1));
	return (1);
}

int		convertprecision(char **str, t_check **stock, va_list vl)
{
	(*stock)->sizetype = ((*stock)->plus == '+' || (*stock)->space == ' '
	|| (*stock)->sign == '-') ? ft_strlen(*str) - (*stock)->lenstr - 1
	: ft_strlen(*str) - (*stock)->lenstr;
	if ((*stock)->prec && (*stock)->prec != -1
	&& (*stock)->prec > (*stock)->sizetype && (*stock)->type != 's')
	{
		if (!convertprecisionwos(str, stock))
			return (0);
	}
	else if ((*stock)->prec && (*stock)->prec > (*stock)->sizetype
	&& (*stock)->type == 's')
	{
		if (!(*str = ft_strjoinf(*str, ft_strsub(va_arg(vl, char *), 0,
		(*stock)->prec), 3)))
			return (0);
	}
	else if ((*stock)->type == 's' && (*stock)->prec == 0)
		va_arg(vl, char *);
	return (convertwidth(str, stock));
}
