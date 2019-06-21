/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_majr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 22:59:10 by qgirard           #+#    #+#             */
/*   Updated: 2019/06/21 07:45:39 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		initialize_name_test(t_elem **new, t_elem **infos, int var, int dir)
{
	if (dir > 0)
	{
		if (var == 1 || var == -1)
		{
			if (!((*new)->name_dir = ft_strdup((*new)->name)))
				return (0);
		}
		else if ((*infos) && (*infos)->name_dir)
		{
			if (!((*new)->name_dir = ft_strdup((*infos)->name_dir)))
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

int		create_test(t_elem **infos, char *str, int var, t_info *stock)
{
	t_elem	*tmp;
	t_elem	*new;

	tmp = (*infos);
	tmp = ((*infos) && tmp->next) ? tmp->next : NULL;
	if (!(new = (t_elem *)malloc(sizeof(t_elem))))
		return (0);
	if (!(new->name = ft_strdup(str)))
		return (0);
	if (!initialize_name_test(&new, (stock->j > 0) ? infos : &tmp, var, stock->dir))
		return (0);
	new->in_dir = stock->dir + 1;
	new->next = NULL;
	if (!(*infos))
	{
		new->prev = NULL;
		(*infos) = new;
	}
	else
	{
		new->prev = (*infos);
		(*infos)->next = new;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
	}
	return (1);
}

int		list_with_test(t_elem **infos, char *str, t_info *stock)
{
	struct stat temp;

	stat(str, &temp);
	if (S_ISREG(temp.st_mode))
	{
		if (!(create_test(infos, str, 8, stock)))
			return (0);
		temp.st_mode = 0;
	}
	else
		ft_printf("%s\n", usage_false_dir(str));
	return (1);
}

int		stock_test(t_elem **infos, char *str, int args, t_info *stock)
{
	stock->dir++;
	if (args > 1)
		if (!(create_test(infos, str, 1, stock)))
			return (0);
	if (args == 1)
		if (!(create_test(infos, str, -1, stock)))
			return (0);
	return (1);
}

int		list_test(t_elem **infos, char *str, int point, t_info *stock)
{
	DIR				*tmp;
	struct dirent	*buf;
	t_elem			*ptr;

	tmp = NULL;
	buf = NULL;
	ptr = (*infos);
	if (stock->dir == 0)
		stock->dir = (stock->j > 2) ? stock->j : 2;
	if (!(tmp = opendir(str)))
		list_with_test(&ptr, str, stock);
	else
	{
		if (!(stock_test(&ptr, str, 2, stock)))
			return (0);
		while ((buf = readdir(tmp)) != NULL)
		{
			if (ptr->next && stock->j > 0)
				ptr = ptr->next;
			if (point == 1 || (ft_strncmp(buf->d_name, ".", 1) && point == 0))
				if (!(create_test(&ptr, buf->d_name, buf->d_type, stock)))
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
				if (!list_test(&tmp, buf, 1, stock))
					return (0);
			if (!stock->a)
				if (!list_test(&tmp, buf, 0, stock))
					return (0);
			ft_strdel(&buf);
		}
		tmp = tmp->next;
	}
	return (1);
}
