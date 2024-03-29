/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_option.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:54:48 by qgirard           #+#    #+#             */
/*   Updated: 2019/06/26 00:26:28 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		a_option(t_elem **ptr, int i)
{
	ft_printf("IN_DIR %d\n", (*ptr)->in_dir);
	if ((*ptr)->type == 10)
	{
		if (i == 1 || (i == 0 && ft_strncmp((*ptr)->name, ".", 1)))
			ft_printf("{rose}%s\n", (*ptr)->name);
	}
	else if ((*ptr)->type == 4)
	{
		if (i == 1 || (i == 0 && ft_strncmp((*ptr)->name, ".", 1)))
			ft_printf("{cyan}%s\n", (*ptr)->name);
	}
	else if ((*ptr)->type != 1 && (*ptr)->type != -1)
	{
		if (i == 1 || (i == 0 && ft_strncmp((*ptr)->name, ".", 1)))
			ft_printf("%s\n", (*ptr)->name);
	}
	if ((*ptr)->type == 1)
		ft_printf("%s:\n", (*ptr)->name);
	if ((*ptr) && (*ptr)->next && (*ptr)->in_dir < (*ptr)->next->in_dir)
		ft_putchar('\n');
	return (0);
}
