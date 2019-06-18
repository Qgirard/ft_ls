/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:29:47 by qgirard           #+#    #+#             */
/*   Updated: 2019/01/18 17:13:39 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*tmp;

	i = 0;
	j = 0;
	if (s)
		tmp = ft_strdup(s);
	if (s == NULL)
		tmp = ft_strdup("(null)");
	while (tmp[i] && i < start)
		i++;
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	while (j < len)
	{
		str[j] = tmp[i];
		j++;
		i++;
	}
	str[j] = '\0';
	ft_strdel(&tmp);
	return (str);
}
