/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertfloats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:30:48 by qgirard           #+#    #+#             */
/*   Updated: 2019/01/24 19:24:12 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	puttopow(t_check **stock)
{
	int		j;
	int		k;
	char	*tmp;

	j = 0;
	k = 0;
	if ((*stock)->prec == -1)
		(*stock)->prec = 6;
	while (j < (*stock)->prec + 1)
	{
		(*stock)->number = (*stock)->number * 10;
		j++;
	}
	tmp = ft_ultoa_base((*stock)->number, 10);
	if (tmp[(*stock)->prec] >= 53 && tmp[(*stock)->prec] <= 56)
		k = 1;
	ft_strdel(&tmp);
	return ((k == 1) ? (*stock)->number / 10 + 1 : ((*stock)->number + 1) / 10);
}

int				convertfloats(char **str, t_check **stock, va_list vl)
{
	int				i;
	unsigned long	u;

	(*stock)->number = va_arg(vl, double);
	i = ((int)(*stock)->number);
	if (!(*str = ft_strjoinf(*str, ft_itoa(i), 3)))
		return (0);
	if (!(*str = ft_strjoinf(*str, ".", 1)))
		return (0);
	(*stock)->number = (*stock)->number - i;
	u = puttopow(stock);
	if (!(*str = ft_strjoinf(*str, ft_ultoa_base(u, 10), 3)))
		return (0);
	return (convertwidth(str, stock));
}
