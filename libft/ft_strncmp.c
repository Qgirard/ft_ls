/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:59:40 by qgirard           #+#    #+#             */
/*   Updated: 2018/11/16 18:15:01 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	while ((s1[i] && s2[i]) && (s1[i] == s2[i]))
		i++;
	if (i >= n)
		return (0);
	a = s1[i];
	b = s2[i];
	return (a - b);
}
