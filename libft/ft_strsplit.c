/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:06:56 by qgirard           #+#    #+#             */
/*   Updated: 2018/11/16 17:06:19 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numberwords(char const *s, char c)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			nb++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (nb);
}

static char	**realsplit(char const *s, char c, int i, int k)
{
	char	**tab;
	int		j;

	if (!(tab = (char **)malloc(sizeof(char *) * (numberwords(s, c)) + 1)))
		return (NULL);
	tab[numberwords(s, c)] = NULL;
	while (s[i] && k < numberwords(s, c))
	{
		j = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (!(tab[k] = (char *)malloc(sizeof(char) * (j) + 1)))
			return (NULL);
		ft_strncpy(tab[k], &s[i], j);
		tab[k][j] = '\0';
		i = i + j;
		k++;
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (s != NULL)
		return (realsplit(s, c, i, k));
	return (NULL);
}
