/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:00:38 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/11 18:59:05 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_converter(long long n, long long i, long long j)
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

char		*ft_lltoa(long long n)
{
	long long	i;
	long long	j;
	long long	k;

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
