/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_option.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:20:33 by qgirard           #+#    #+#             */
/*   Updated: 2019/06/19 03:11:18 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		l_option(t_info *stock, t_elem **ptr)
{
	//time_t *mtime;
	//int n;
	long ret;
	char *path;
	//n = 16;
	//stat((*ptr)->name, &(*ptr)->buf);
	//mtime = &(*ptr)->buf.st_mtimespec.tv_sec;
	ret = get_timestamp((*ptr)->name);
	path = NULL;
	if ((*ptr)->name_dir)
	{
		path = ft_strjoin((*ptr)->name_dir, "/");
		path = ft_strjoinf(path, (*ptr)->name, 1);
		ret = get_timestamp(path);
	}
	if (*ptr && ((ft_strncmp((*ptr)->name, ".", 1)
	|| ((*ptr)->name_dir && !ft_strcmp((*ptr)->name_dir, ".") && (*ptr)->prev))
	|| stock->a))
	{
		//print_block((*ptr)->name);
		if ((*ptr)->type == 1)
			(stock->a) ? a_option(ptr, 1) : a_option(ptr, 0);
		else
		{
			((*ptr)->name_dir) ? rights_modes(path, stock)
			: rights_modes((*ptr)->name, stock);
			((*ptr)->name_dir) ? get_uid_gid(path, stock)
			: get_uid_gid((*ptr)->name, stock);
			print_timestamp(ret);
			ft_printf(" ");
			(stock->a) ? a_option(ptr, 1) : a_option(ptr, 0);
		}
	}
	if (path)
		ft_strdel(&path);
	return (1);
}

long get_timestamp(char *dir)
{
	struct stat *sb;
	int 		ret;

	ret = 0;
	sb = malloc(sizeof(struct stat));
	if (lstat(dir, sb) == -1)
		ret = -1;
	else
		ret = sb->st_mtime;
	free(sb);
	return(ret);
}

void 		print_timestamp(long timestamp)
{
	char *ret;

	if ((ret = ctime(&timestamp) + 4) == NULL)
	 	return ;
	ret[12] = '\0';
	ft_printf("%s", ret);
}

int 	block(t_elem **ptr)
{
	DIR 			*dir;
	int 			ret;
	struct dirent 	*dirent = NULL;
	struct stat		*sb = NULL;
	char 			*str;

	ret = 0;
	str = (*ptr)->name;
	if (!(dir = opendir(str)))
		return -1;
	else
		while((dirent = readdir(dir)) != NULL)
			ret += sb->st_blocks;
	return(ret);
}

void 	print_block(char *dir)
{
	int ret;
	struct stat  sb;

	ret = 0;
	lstat(dir,&sb);

	//while()

	// ft_printf("total %d", ret);
}
/*
int main(int ac, char **av)
{
	int i;
	(void)ac;
	i = 1;
	while(av[i])
	{
		printf("%ld ", get_timestamp(av[i]));
		print_timestamp(get_timestamp(av[i]));
		printf("%s ",av[i]);
		printf("\n");
		i++;
	}
	return(0);
}
*/
