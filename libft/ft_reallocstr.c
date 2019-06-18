/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallocstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:57:05 by qgirard           #+#    #+#             */
/*   Updated: 2018/12/20 15:26:22 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reallocstr(char *ptr, size_t size)
{
	char	*new;

	if (!size && ptr)
	{
		if (!(new = (char *)malloc(1)))
			return (NULL);
		new[0] = '\0';
		ft_strdel(&ptr);
		return (new);
	}
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new[size] = '\0';
	if (ptr)
	{
		ft_strcpy(new, ptr);
		ft_strdel(&ptr);
	}
	return (new);
}
