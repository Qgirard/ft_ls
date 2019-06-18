/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:54:29 by qgirard           #+#    #+#             */
/*   Updated: 2018/11/13 11:43:27 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*str;

	i = 0;
	ptr = (unsigned char *)dst;
	str = (unsigned char *)src;
	if (src < dst)
	{
		while ((int)(--len) >= 0)
			*(ptr + len) = *(str + len);
	}
	else
	{
		while (i < len)
		{
			*(ptr + i) = *(str + i);
			i++;
		}
	}
	return (dst);
}
