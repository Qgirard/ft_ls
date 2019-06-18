/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:46:49 by qgirard           #+#    #+#             */
/*   Updated: 2018/11/19 14:45:52 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	ptr = (char *)haystack;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i] && needle[j] && needle[j] == haystack[i])
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
