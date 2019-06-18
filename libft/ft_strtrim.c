/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:00:54 by qgirard           #+#    #+#             */
/*   Updated: 2018/11/19 17:29:27 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_realtrim(char const *s, size_t i, size_t j, size_t k)
{
	char	*str;

	while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t')
		i++;
	if (!s[k])
		k--;
	while (s[k] == '\n' || s[k] == ' ' || s[k] == '\t')
	{
		k--;
		j++;
	}
	if (i == j && i == ft_strlen(s))
		str = ft_strsub(s, i, 0);
	else
		str = ft_strsub(s, i, ft_strlen(s) - i - j);
	return (str);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (s != NULL)
	{
		k = ft_strlen(s);
		return (ft_realtrim(s, i, j, k));
	}
	return (NULL);
}
