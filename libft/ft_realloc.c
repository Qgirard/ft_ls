/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:51:21 by qgirard           #+#    #+#             */
/*   Updated: 2018/12/20 14:09:23 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*new;

	if (!size && ptr)
	{
		if (!(new = (char *)malloc(1)))
			return (NULL);
		ft_memdel(&ptr);
		return (new);
	}
	if (!(new = (char *)malloc(size)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(new, ptr, size);
		ft_memdel(&ptr);
	}
	return (new);
}
