/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:51:07 by qgirard           #+#    #+#             */
/*   Updated: 2018/11/13 11:43:20 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*str;

	i = 0;
	ptr = (unsigned char *)s1;
	str = (unsigned char *)s2;
	while (i < n)
	{
		if (ptr[i] != str[i])
			return (ptr[i] - str[i]);
		i++;
	}
	return (0);
}
