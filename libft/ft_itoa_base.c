/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:23:29 by qgirard           #+#    #+#             */
/*   Updated: 2018/12/19 18:46:59 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_converter(int n, long i, long j, int base)
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
		if (n % base < 10)
			str[j] = n % base + '0';
		else
			str[j] = n % base - 10 + 'a';
		n = n / base;
		j--;
	}
	return (str);
}

char		*ft_itoa_base(int n, int base)
{
	long	i;
	long	j;
	long	k;

	i = 0;
	k = n;
	if (n == -2147483648 && base == 10)
		return (ft_strdup("-2147483648"));
	if (n <= 0)
		i = 1;
	while (k != 0)
	{
		k = k / base;
		i++;
	}
	j = i;
	return (ft_converter(n, i, j, base));
}
