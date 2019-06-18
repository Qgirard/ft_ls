/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uid_gid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:46:16 by qgirard           #+#    #+#             */
/*   Updated: 2019/06/19 00:48:27 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_uid_gid(char *str)
{
	struct stat		buf;
	struct passwd	*stock;
	struct group	*temp;

	if (str)
	{
		if (stat(str, &buf) == 0)
		{
			stock = getpwuid(buf.st_uid);
			temp = getgrgid(buf.st_gid);
			ft_printf("%4u", buf.st_nlink);
			if (stock)
				ft_printf(" %s", stock->pw_name);
			else
				ft_printf(" %u", buf.st_uid);
			ft_printf("  %s ", temp->gr_name);
			ft_printf("%6lld ", buf.st_size);
			return (1);
		}
	}
	return (0);
}
