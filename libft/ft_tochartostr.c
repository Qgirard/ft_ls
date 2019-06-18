/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tochartostr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:22:57 by qgirard           #+#    #+#             */
/*   Updated: 2018/12/19 18:31:59 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tochartostr(int i)
{
	unsigned char	c;
	char			*str;

	if (!(str = (char *)ft_memalloc(sizeof(char))))
		return (NULL);
	c = i;
	str[0] = c;
	str[1] = '\0';
	return (str);
}
