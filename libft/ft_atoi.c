/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:09:54 by qgirard           #+#    #+#             */
/*   Updated: 2018/11/16 16:33:38 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	realatoi(const char *str, long i, long j, long k)
{
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == ' ')
		i++;
	if ((str[i] == '-') && (str[i + 1] >= 48 && str[i + 1] <= 57))
	{
		j = -1;
		i++;
	}
	if ((str[i] == '+') && (str[i + 1] >= 48 && str[i + 1] <= 57))
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (k > 2147483647 && j == 1)
			return (-1);
		if (k > 2147483648 && j == -1)
			return (0);
		k = k * 10 + str[i] - '0';
		i++;
	}
	return (k * j);
}

int			ft_atoi(const char *str)
{
	long i;
	long k;
	long j;

	i = 0;
	k = 0;
	j = 1;
	return (realatoi(str, i, j, k));
}
