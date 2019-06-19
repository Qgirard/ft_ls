/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rights_modes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:18:46 by qgirard           #+#    #+#             */
/*   Updated: 2019/06/19 06:06:58 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	nodes(char *str)
{
	struct stat	tmp;

	stat(str, &tmp);
	S_ISDIR(tmp.st_mode) ? ft_printf("d") : 0;
	S_ISREG(tmp.st_mode) ? ft_printf("-") : 0;
	S_ISLNK(tmp.st_mode) ? ft_printf("l") : 0;
	S_ISBLK(tmp.st_mode) ? ft_printf("b") : 0;
	S_ISCHR(tmp.st_mode) ? ft_printf("c") : 0;
	S_ISFIFO(tmp.st_mode) ? ft_printf("p") : 0;
	S_ISSOCK(tmp.st_mode) ? ft_printf("s") : 0;
	ft_printf((tmp.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((tmp.st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((tmp.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((tmp.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((tmp.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((tmp.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((tmp.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((tmp.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((tmp.st_mode & S_IXOTH) ? "x" : "-");
}

int		rights_modes(char *str)
{
	nodes(str);
	return (1);
}
