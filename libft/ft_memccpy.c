/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:04:59 by qgirard           #+#    #+#             */
/*   Updated: 2018/11/13 11:43:11 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*str;

	i = 0;
	ptr = (unsigned char *)dst;
	str = (unsigned char *)src;
	while (i < n)
	{
		ptr[i] = str[i];
		if (str[i] == (unsigned char)c)
			return (ptr + i + 1);
		i++;
	}
	return (NULL);
}
