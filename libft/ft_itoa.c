/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:39:12 by qgirard           #+#    #+#             */
/*   Updated: 2018/11/16 15:46:41 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_converter(int n, long i, long j)
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

char		*ft_itoa(int n)
{
	long	i;
	long	j;
	long	k;

	i = 0;
	k = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
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
