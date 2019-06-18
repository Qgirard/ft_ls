/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:48:30 by qgirard           #+#    #+#             */
/*   Updated: 2018/11/21 16:56:47 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*concatener(char const *s1, char const *s2, int i, int j)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(*str) *
		(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 != NULL && s2 != NULL)
	{
		return (concatener(s1, s2, i, j));
	}
	return (NULL);
}
