/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:01:45 by qgirard           #+#    #+#             */
/*   Updated: 2018/12/20 15:25:20 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_converter(unsigned int n, long i, long j, int base)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(*str) * i + 1)))
		return (NULL);
	str[j] = '\0';
	j--;
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

char		*ft_utoa_base(unsigned int n, int base)
{
	long			i;
	long			j;
	unsigned long	k;

	i = 0;
	k = n;
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
