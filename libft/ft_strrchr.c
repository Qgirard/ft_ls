/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:39:39 by qgirard           #+#    #+#             */
/*   Updated: 2018/11/16 15:44:07 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ptr;

	ptr = (char *)s;
	while (*ptr)
		ptr++;
	while (*ptr != c && *ptr != s[0])
		ptr--;
	return ((*ptr == c) ? ptr : NULL);
}
