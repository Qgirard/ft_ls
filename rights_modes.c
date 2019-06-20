/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rights_modes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:18:46 by qgirard           #+#    #+#             */
/*   Updated: 2019/06/20 05:24:24 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sticky_bits(char *bit, int i, int k)
{
	if (i == 1)
	{
		if (bit[k] == '4' || bit[k] == '5' || bit[k] == '6' || bit[k] == '7')
			(bit[k + 1] & 00000001) ? ft_putchar('s') : ft_putchar('S');
	}
	else if (i == 2)
	{
		if (bit[k] == '2' || bit[k] == '3' || bit[k] == '6' || bit[k] == '7')
			(bit[k + 2] & 00000001) ? ft_putchar('s') : ft_putchar('S');
	}
	else if (i == 3)
	{
		if (bit[k] == '1' || bit[k] == '3' || bit[k] == '5' || bit[k] == '7')
			(bit[k + 3] & 00000001) ? ft_putchar('t') : ft_putchar('T');
	}
}

void	write_rights(struct stat tmp)
{
	char		*sticky_bit;
	int		k;

	sticky_bit = ft_itoa_base(tmp.st_mode, 8);
	k = (ft_strlen(sticky_bit) >= 6) ? 2 : 1;
	ft_printf((tmp.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((tmp.st_mode & S_IWUSR) ? "w" : "-");
	if (sticky_bit[k] != '0')
		sticky_bits(sticky_bit, 1, k);
	else
		ft_printf((tmp.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((tmp.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((tmp.st_mode & S_IWGRP) ? "w" : "-");
	if (sticky_bit[k] != '0')
		sticky_bits(sticky_bit, 2, k);
	else
		ft_printf((tmp.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((tmp.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((tmp.st_mode & S_IWOTH) ? "w" : "-");
	if (sticky_bit[k] != '0')
		sticky_bits(sticky_bit, 3, k);
	else
		ft_printf((tmp.st_mode & S_IXOTH) ? "x" : "-");
	ft_strdel(&sticky_bit);
}

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
	write_rights(tmp);
}

int		rights_modes(char *str)
{
	nodes(str);
	return (1);
}
