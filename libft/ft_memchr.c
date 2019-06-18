/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:12:53 by qgirard           #+#    #+#             */
/*   Updated: 2018/11/16 17:51:01 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	k;

	i = 0;
	ptr = (unsigned char *)s;
	k = (unsigned char)c;
	while (i < n)
	{
		if (ptr[i] == k)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
