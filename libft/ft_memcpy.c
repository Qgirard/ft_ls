/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:39:36 by qgirard           #+#    #+#             */
/*   Updated: 2018/11/13 11:43:24 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*str;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)dst;
	str = (unsigned char *)src;
	while (i < n)
	{
		ptr[i] = str[i];
		i++;
	}
	return (dst);
}
