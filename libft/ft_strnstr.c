/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:45:04 by qgirard           #+#    #+#             */
/*   Updated: 2018/11/13 11:44:28 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	ptr = (char *)haystack;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] && i < (int)len)
	{
		j = 0;
		while (i < (int)len && haystack[i] && needle[j]
			&& needle[j] == haystack[i])
		{
			if (!(needle[j + 1]) && haystack[i] == needle[j])
				return (ptr + i - j);
			j++;
			i++;
		}
		i -= (needle[j] == haystack[i]) ? j - 1 : j;
		i++;
	}
	return (NULL);
}
