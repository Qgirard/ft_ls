/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_option.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:20:33 by qgirard           #+#    #+#             */
/*   Updated: 2019/06/20 09:09:37 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 		print_timestamp(long timestamp)
{
	char *ret;

	if ((ret = ctime(&timestamp) + 4) == NULL)
	 	return ;
	ret[12] = '\0';
	ft_printf("%s", ret);
}

long get_timestamp(char *dir)
{
	struct stat	*sb;
	int 		ret;

	ret = 0;
	if (!(sb = malloc(sizeof(struct stat))))
		return (-2);
	if (lstat(dir, sb) == -1)
		ret = -1;
	else
		ret = sb->st_mtime;
	free(sb);
	return(ret);
}

int		ft_total_blocks(t_elem **ptr, t_info *options)
{
	struct stat buf;
	int			compt;
	t_elem		*list;
	char		*path;

	list = (*ptr);
	compt = 0;
	while (list)
	{
		if (list->type == 1 || list->type == -1)
			if (list->next)
				list = list->next;
		path = NULL;
		if (list->name_dir)
		{
			path = ft_strjoinf(list->name_dir, "/", 0);
			path = ft_strjoinf(path, list->name, 1);
		}
		(path) ? lstat(path, &buf) : lstat(list->name, &buf);
		if (buf.st_blocks)
		{
			if (options->a)
				compt += buf.st_blocks;
			else if (list->name[0] != '.')
				compt += buf.st_blocks;
		}
		if (list->next && list->in_dir != list->next->in_dir)
			return (compt);
		list = list->next;
	}
	return (compt);
}

int		l_option(t_info *stock, t_elem **ptr)
{
	long ret;
	char *path;

	if ((ret = get_timestamp((*ptr)->name) == 2))
		return (0);
	path = NULL;
	if ((*ptr)->name_dir)
	{
		path = ft_strjoin((*ptr)->name_dir, "/");
		path = ft_strjoinf(path, (*ptr)->name, 1);
		ret = get_timestamp(path);
	}
	if ((*ptr)->type == -1)
		ft_printf("total %d\n", ft_total_blocks(ptr, stock));
	if (*ptr && ((ft_strncmp((*ptr)->name, ".", 1)
	|| ((*ptr)->name_dir && !ft_strcmp((*ptr)->name_dir, ".") && (*ptr)->prev))
	|| stock->a || (*ptr)->type == 1) && (*ptr)->type != -1)
	{
		if ((*ptr)->type == 1)
		{
			(stock->a) ? a_option(ptr, 1) : a_option(ptr, 0);
			if ((*ptr)->in_dir == (*ptr)->next->in_dir)
				ft_printf("total %d\n", ft_total_blocks(ptr, stock));
		}
		else
		{
			((*ptr)->name_dir) ? rights_modes(path)
			: rights_modes((*ptr)->name);
			((*ptr)->name_dir) ? get_uid_gid(path, ptr)
			: get_uid_gid((*ptr)->name, ptr);
			print_timestamp(ret);
			ft_printf(" ");
			(stock->a) ? a_option(ptr, 1) : a_option(ptr, 0);
		}
	}
	if (path)
		ft_strdel(&path);
	return (1);
}