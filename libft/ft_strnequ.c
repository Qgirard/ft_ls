/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:23:51 by qgirard           #+#    #+#             */
/*   Updated: 2018/11/16 18:38:16 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		if (n == 0)
			return (1);
		while ((i < n) && (s1[i] != '\0' && s2[i] != '\0') && (s1[i] == s2[i]))
			i++;
		if (i == n && s1[i] != s2[i])
			i--;
		return ((s1[i] == s2[i]) ? 1 : 0);
	}
	return (0);
}
