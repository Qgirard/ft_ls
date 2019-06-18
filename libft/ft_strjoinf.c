/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:54:27 by qgirard           #+#    #+#             */
/*   Updated: 2019/01/31 18:12:14 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinf(char *s1, char *s2, size_t rm)
{
	char			*new_s;
	unsigned int	i;
	unsigned int	j;
	int				tmp;

	tmp = 0;
	if ((int)rm < 0 || (int)rm > 3)
		return (NULL);
	if (!s2)
	{
		tmp = 1;
		s2 = ft_strdup("(null)");
	}
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if ((new_s = ft_strnew(i + j)) == NULL)
		return (NULL);
	ft_strcpy(new_s, s1);
	ft_strcat(new_s, s2);
	if (rm == 1 || rm == 3)
		ft_strdel(&s1);
	if ((rm == 2 || rm == 3 || (!ft_strcmp(s2, "(null)") && tmp == 1)))
		ft_strdel(&s2);
	return (new_s);
}
