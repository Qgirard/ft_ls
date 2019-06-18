/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_args_time_rev.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 03:58:56 by qgirard           #+#    #+#             */
/*   Updated: 2019/06/14 04:07:35 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		args_by_time_rev(char **argv, int i)
{
	while (argv[i] && argv[i + 1])
	{
		if (get_timestamp(argv[i]) > get_timestamp(argv[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int		sort_args_time_rev(char **argv, int i)
{
	char	*tmp;
	int		j;

	while (!args_by_time_rev(argv, i))
	{
		j = i;
		while (argv[j] && argv[j + 1])
		{
			if (get_timestamp(argv[j]) > get_timestamp(argv[j + 1]))
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
