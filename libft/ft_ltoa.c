/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:16:57 by qgirard           #+#    #+#             */
/*   Updated: 2018/12/21 15:06:32 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_converter(long n, long i, long j)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(*str) * i + 1)))
		return (NULL);
	str[j] = '\0';
	j--;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
		str[j] = '0';
	while (n != 0)
	{
		str[j] = n % 10 + '0';
		n = n / 10;
		j--;
	}
	return (str);
}

char		*ft_ltoa(long n)
{
	long	i;
	long	j;
	long	k;

	i = 0;
	k = n;
	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (n <= 0)
		i = 1;
	while (k != 0)
	{
		k = k / 10;
		i++;
	}
	j = i;
	return (ft_converter(n, i, j));
}
