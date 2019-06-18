/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sctoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:24:48 by qgirard           #+#    #+#             */
/*   Updated: 2019/01/17 16:03:39 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_converter(signed char n, short i, short j)
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

char		*ft_sctoa(signed char n)
{
	short		i;
	short		j;
	signed char	k;

	i = 0;
	k = n;
	if (n == -128)
		return (ft_strdup("-128"));
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
