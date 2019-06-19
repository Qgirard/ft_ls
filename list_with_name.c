/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_with_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:23:54 by qgirard           #+#    #+#             */
/*   Updated: 2019/06/19 22:48:12 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		initialize_name_dir(t_elem **new, t_elem *tmp, int var, int dir)
{
	if (dir > 0)
	{
		if (var == 1 || var == -1)
		{
			if (!((*new)->name_dir = ft_strdup((*new)->name)))
				return (0);
		}
		else if (tmp && tmp->name_dir)
			if (!((*new)->name_dir = ft_strdup(tmp->name_dir)))
				return (0);
	}
	else
		(*new)->name_dir = NULL;
	return (1);
}

int		create_list(t_elem **infos, char *str, int var, int dir)
{
	t_elem	*tmp;
	t_elem	*new;

	tmp = (*infos);
	while ((*infos) && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_elem *)malloc(sizeof(t_elem))))
		return (0);
	if (!(new->name = ft_strdup(str)))
		return (0);
	if (!initialize_name_dir(&new, tmp, var, dir))
		return (0);
	new->type = var;
	new->in_dir = dir;
	new->next = NULL;
	if (!(*infos))
	{
		new->prev = NULL;
		(*infos) = new;
	}
	else
	{
		new->prev = tmp;
		tmp->next = new;
	}
	return (1);
}

int		list_with_file(t_elem **infos, char *str)
{
	struct stat temp;

	stat(str, &temp);
	if (S_ISREG(temp.st_mode))
	{
		if (!(create_list(infos, str, 8, 0)))
			return (0);
		temp.st_mode = 0;
	}
	else
		ft_printf("%s\n", usage_false_dir(str));
	return (1);
}

int		stock_dirs(t_elem **infos, char *str, int args, int *dir)
{
	(*dir) = (*dir) + 1;
	if (args > 1)
		if (!(create_list(infos, str, 1, *dir)))
			return (0);
	if (args == 1)
		if (!(create_list(infos, str, -1, *dir)))
			return (0);
	return (1);
}

int		list_with_name(t_elem **infos, char *str, int point, int args)
{
	DIR				*tmp;
	static int		dir;
	struct dirent	*buf;

	tmp = NULL;
	buf = NULL;
	if (!infos)
		dir = 0;
	if (!(tmp = opendir(str)))
		list_with_file(infos, str);
	else
	{
		if (!(stock_dirs(infos, str, args, &dir)))
			return (0);
		while ((buf = readdir(tmp)) != NULL)
		{
			if (point == 1 || (ft_strncmp(buf->d_name, ".", 1) && point == 0))
				if (!(create_list(infos, buf->d_name, buf->d_type, dir)))
					return (0);
		}
		closedir(tmp);
	}
	return (1);
}
