/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_majr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 22:59:10 by qgirard           #+#    #+#             */
/*   Updated: 2019/06/26 00:32:17 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		initialize_dirs_majr(t_elem **new, t_elem *tmp, int var, t_info *stock)
{
	if (stock->dir)
	{
		if (var == 1 || var == -1)
		{
			if (!((*new)->name_dir = ft_strdup((*new)->name)))
				return (0);
		}
		else if (tmp && tmp->name_dir)
		{
			if (!((*new)->name_dir = ft_strdup(tmp->name_dir)))
				return (0);
		}
		else
			(*new)->name_dir = NULL;
	}
	else
		(*new)->name_dir = NULL;
	(*new)->type = var;
	return (1);
}

int		create_majr(t_elem **infos, char *str, int var, t_info *stock)
{
	t_elem	*tmp;
	t_elem	*new;
	t_elem	*ptr;

	tmp = (*infos);
	ptr = ((*infos) && (*infos)->next) ? (*infos)->next : NULL;
	if (!(new = (t_elem *)malloc(sizeof(t_elem))))
		return (0);
	if (!(new->name = ft_strdup(str)))
		return (0);
	if (!initialize_dirs_majr(&new, tmp, var, stock))
		return (0);
	new->in_dir = stock->dir;
	new->next = NULL;
	if (ptr)
	{
		ptr->prev = new;
		new->next = ptr;
	}
	new->prev = tmp;
	tmp->next = new;
	(*infos) = (*infos)->next;
	return (1);
}

int		stock_dirs_majr(t_elem **infos, char *str, int args, t_info *stock)
{
	if (args > 1)
		if (!(create_majr(infos, str, 1, stock)))
			return (0);
	if (args == 1)
		if (!(create_majr(infos, str, -1, stock)))
			return (0);
	return (1);
}

int		list_majr(t_elem **infos, char *str, int point, t_info *stock)
{
	DIR				*tmp;
	struct dirent	*buf;
	t_elem			*ptr;
	t_elem			*temp;

	tmp = NULL;
	buf = NULL;
	ptr = (*infos);
	temp = (*infos);
	if (!(tmp = opendir(str)))
	{
		ft_putendl("ERROR");
		return (0);
	}
	else
	{
		stock->dir = (stock->dir) ? stock->dir + 1 : (*infos)->prev->in_dir + 1;
		while (temp)
		{
			while (temp && temp->next && (temp->in_dir == temp->next->in_dir
			|| temp->in_dir > temp->next->in_dir))
				temp = temp->next;
			temp = (temp->next) ? temp->next : NULL;
			while (temp)
			{
				temp->in_dir++;
				temp = temp->next;
			}
		}
		if (!(stock_dirs_majr(&ptr, str, 2, stock)))
			return (0);
		while ((buf = readdir(tmp)) != NULL)
		{
			if (point == 1 || (ft_strncmp(buf->d_name, ".", 1) && point == 0))
				if (!(create_majr(&ptr, buf->d_name, buf->d_type, stock)))
					return (0);
		}
		closedir(tmp);
	}
	return (1);
}

int		stock_majr(t_elem **infos, t_info *stock, char *str)
{
	t_elem	*tmp;
	char	*buf;

	tmp = (*infos);
	buf = NULL;
	while (tmp)
	{
		if (tmp->type == 4 && ft_strcmp(".", tmp->name)
		&& ft_strcmp("..", tmp->name) && str == NULL)
		{
			buf = (tmp->name_dir) ? ft_strjoin(tmp->name_dir, "/")
			: ft_strjoin(".", "/");
			buf = ft_strjoinf(buf, tmp->name, 1);
			if (stock->a)
				if (!list_majr(&tmp, buf, 1, stock))
					return (0);
			if (!stock->a)
				if (!list_majr(&tmp, buf, 0, stock))
					return (0);
			ft_strdel(&buf);
		}
		tmp = tmp->next;
	}
	return (1);
}
