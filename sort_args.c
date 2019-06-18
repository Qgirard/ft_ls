/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 03:11:19 by qgirard           #+#    #+#             */
/*   Updated: 2019/06/14 03:17:56 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		args_are_sort(char **argv, int i)
{
	while (argv[i] && argv[i + 1])
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int		sort_args(char **argv, int i)
{
	char	*tmp;
	int		j;

	while (!args_are_sort(argv, i))
	{
		j = i;
		while (argv[j] && argv[j + 1])
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				tmp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = tmp;
			}
			j++;
		}
	}
	return (1);
}
