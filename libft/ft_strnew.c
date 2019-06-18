/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:18:03 by qgirard           #+#    #+#             */
/*   Updated: 2018/11/13 12:37:17 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ptr;

	if (!(ptr = (char *)malloc(sizeof(*ptr) * ((int)size) + 1)))
		return (NULL);
	ft_bzero(ptr, size + 1);
	return (ptr);
}
