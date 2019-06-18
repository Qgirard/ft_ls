/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:10:31 by qgirard           #+#    #+#             */
/*   Updated: 2018/11/14 12:39:23 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		if (!(ptr = (char *)malloc(sizeof(*ptr) * (ft_strlen(s)) + 1)))
			return (NULL);
		while (s[i])
		{
			ptr[i] = f(s[i]);
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	return (NULL);
}
