/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:29:47 by qgirard           #+#    #+#             */
/*   Updated: 2019/06/20 22:46:36 by qgirard          ###   ########.fr       */
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
	while (tmp[i] && j < len)
	{
		str[j] = tmp[i];
		j++;
		i++;
	}
	str[j] = '\0';
	ft_strdel(&tmp);
	return (str);
}
