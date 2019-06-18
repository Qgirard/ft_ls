/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertwidth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:47:23 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/14 18:32:16 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convertwidtherror(char **str, t_check **stock, char **tmp, char **ptr)
{
	if (!(*stock)->hexaex)
	{
		if (!(*str = ((*stock)->type == 'x') ? ft_strjoinf(*str, "0x", 1)
		: ft_strjoinf(*str, "0X", 1)))
			return (convertprecisionerr(tmp, ptr, 3));
	}
	else
	{
		if (!(*str = ft_strjoinf(*str, "0", 1)))
			return (convertprecisionerr(tmp, ptr, 3));
	}
	if (!(*str = ft_strjoinf(*str, *ptr, 3)))
		return (convertprecisionerr(tmp, ptr, 3));
	if (!(*str = ft_strjoinf(*str, *tmp, 3)))
		return (convertprecisionerr(tmp, ptr, 1));
	(*stock)->hexaex = 0;
	return (1);
}

int		convertwidthoptions(char **str, t_check **stock)
{
	char	*tmp;
	char	*ptr;
	int		i;

	i = 0;
	(*stock)->sizetype = ft_strlen(*str) - (*stock)->lenstr;
	if (!(ptr = ft_strsub(*str, 0, (*stock)->lenstr)))
		return (0);
	if (!(tmp = ft_strsub(*str, (*stock)->lenstr + 2, ft_strlen(*str))))
		return (convertprecisionerr(&tmp, &ptr, 2));
	ft_strdel(str);
	if (!(*str = ft_strdup(ptr)))
		return (convertprecisionerr(&tmp, &ptr, 3));
	ft_strdel(&ptr);
	if (!(ptr = ft_reallocstr(NULL, (*stock)->width - (*stock)->sizetype)))
		return (convertprecisionerr(&tmp, &ptr, 1));
	while (i < (*stock)->width - (*stock)->sizetype)
		ptr[i++] = '0';
	if (!convertwidtherror(str, stock, &tmp, &ptr))
		return (0);
	return (1);
}

int		convertwidthforall(char **str, t_check **stock)
{
	char	*tmp;
	char	*ptr;
	int		i;

	i = 0;
	if ((*stock)->diez == '#' && (*stock)->zero == '0'
	&& ((*stock)->type == 'x' || (*stock)->type == 'X'))
		return (convertwidthoptions(str, stock));
	if (!(ptr = ft_reallocstr(NULL, (*stock)->width - (*stock)->sizetype)))
		return (0);
	while (i < (*stock)->width - (*stock)->sizetype)
		ptr[i++] = ((*stock)->zero == '0') ? '0' : ' ';
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

void	initialization(char **str, t_check **stock)
{
	if (((*stock)->plus == '+' || (*stock)->sign == '-'
	|| (*stock)->space == ' ') && ((*stock)->type == 'd'
	|| (*stock)->type == 'D') && ((*stock)->zero == '0'))
		(*stock)->width--;
	(*stock)->sizetype = (((*stock)->plus == '+' || (*stock)->sign == '-'
	|| (*stock)->space == ' ') && ((*stock)->type == 'd'
	|| (*stock)->type == 'D') && ((*stock)->zero == '0'))
	? ft_strlen(*str) - (*stock)->lenstr - 1
	: ft_strlen(*str) - (*stock)->lenstr;
	if ((*stock)->checkex == 1)
		(*stock)->width++;
	if ((*stock)->sizetype >= (*stock)->width
	|| ((*stock)->prec > (*stock)->width && (*stock)->type != 's'))
		(*stock)->width = 0;
}

int		convertwidth(char **str, t_check **stock)
{
	char	*tmp;
	int		i;

	i = 0;
	initialization(str, stock);
	if ((*stock)->width != 0)
	{
		if ((*stock)->less == '-')
		{
			if (!(tmp = ft_reallocstr(NULL,
			(*stock)->width - (*stock)->sizetype)))
				return (0);
			while (i < (*stock)->width - (*stock)->sizetype)
				tmp[i++] = ((*stock)->zero == '0' && ((*stock)->type != 's'
				&& (*stock)->type != 'c')) ? '0' : ' ';
			if (!(*str = ft_strjoinf(*str, tmp, 3)))
				return (convertprecisionerr(&tmp, NULL, 1));
		}
		else
			return (convertwidthforall(str, stock));
	}
	return (1);
}
