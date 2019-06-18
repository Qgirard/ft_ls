/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:13:15 by qgirard           #+#    #+#             */
/*   Updated: 2019/04/04 13:16:40 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	error_arg(char arg)
{
	ft_putstr_fd("ls: illegal option --\n" , 2);
	ft_putchar_fd(arg, 2);
	ft_putstr_fd("usage: ls [-lRart] [file ...]\n")
	exit(EXIT_FAILURE);
}

void error_b(char *name, char *error, int ex)
{
	ft_putstr_fd(name, 2);
	perror(error);
	if (ex)
		exit(EXIT_FAILURE);
}
