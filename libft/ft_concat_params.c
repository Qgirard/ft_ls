/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:15:40 by qgirard           #+#    #+#             */
/*   Updated: 2018/11/19 12:32:13 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_concat_params(int argc, char **argv)
{
	char	*tab;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 1;
	if (!(tab = (char*)malloc(sizeof(*tab) * (argc + 1))))
		return (0);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			tab[k] = argv[i][j];
			k++;
			j++;
		}
		if (i < argc - 1)
			tab[k] = '\n';
		k++;
		i++;
	}
	tab[k] = '\0';
	return (tab);
}
