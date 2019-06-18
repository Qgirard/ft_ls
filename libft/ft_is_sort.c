/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:37:14 by qgirard           #+#    #+#             */
/*   Updated: 2018/11/19 12:45:28 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
		{
			if (j == 0)
				j = 1;
			if (j == -1)
				return (0);
		}
		if (f(tab[i], tab[i + 1]) < 0)
		{
			if (j == 0)
				j = -1;
			if (j == 1)
				return (0);
		}
		i++;
	}
	return (1);
}
