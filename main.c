/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:59:49 by qgirard           #+#    #+#             */
/*   Updated: 2019/06/14 04:57:25 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		checkargs(char *str, t_info *stock)
{
	int		i;

	i = 1;
	if (str[0] == '-')
	{
		while (str[i])
		{
			if (!stockinfos(stock, str[i]))
				return (0);
			i++;
		}
	}
	return (1);
}

int		initializeinfos(t_info *stock)
{
	stock->l = 0;
	stock->majr = 0;
	stock->a = 0;
	stock->r = 0;
	stock->t = 0;
	stock->j = 0;
	return (1);
}

int		args_or_not(t_info *stock, t_elem **infos, int i)
{
	if (i == 0)
	{
		if (stock->a)
			if (!list_with_name(infos, ".", 1, 0))
				return (0);
		if (!stock->a)
			if (!list_with_name(infos, ".", 0, 0))
				return (0);
		sort_in_ascii(infos, stock, 0);
		ft_ls(stock, infos);
	}
	return (1);
}

int		multiple_args(char **argv, t_info *stock, t_elem **infos, int i)
{
	/*if (stock->r)
		(stock->t) ? sort_args_time_rev(argv, i) : sort_args_reverse(argv, i);
	else
		(stock->t) ? sort_args_time(argv, i) : sort_args(argv, i);*/
	sort_args(argv, i);
	while (argv[i])
	{
		i++;
		stock->j = stock->j + 1;
	}
	i = i - stock->j;
	while (argv[i])
	{
		if (stock->a)
			if (!list_with_name(infos, argv[i], 1, stock->j))
				return (0);
		if (!stock->a)
			if (!list_with_name(infos, argv[i], 0, stock->j))
				return (0);
		i++;
	}
	sort_in_ascii(infos, stock, 1);
	ft_ls(stock, infos);
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	t_info	stock;
	t_elem	*infos;

	i = 1;
	infos = NULL;
	if (!(initializeinfos(&stock)))
		return (1);
	if (argc >= 1)
	{
		while (argv[i] && argv[i][0] == '-')
		{
			if (!checkargs(argv[i], &stock))
				return (1);
			i++;
		}
	}
	if (!(argv[i]))
		if (!args_or_not(&stock, &infos, 0))
			return (free_elems(&infos));
	if (argv[i] && (!multiple_args(argv, &stock, &infos, i)))
		return (free_elems(&infos));
	free_elems(&infos);
	return (0);
}
