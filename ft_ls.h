/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:00:09 by qgirard           #+#    #+#             */
/*   Updated: 2019/06/21 04:53:12 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <dirent.h>

typedef struct		s_info
{
	int				l;
	int				less;
	int				majr;
	int				a;
	int				r;
	int				t;
	int				j;
	int				dir;
}					t_info;

typedef struct		s_elem
{
	char			*name;
	int				type;
	int				in_dir;
	char			*name_dir;
	struct s_elem	*next;
	struct s_elem	*prev;
	struct stat 	buf;
	//char 			*time;
}					t_elem;

void 				print_block(char *dir);
long 				get_timestamp(char *dir);
void 				print_timestamp(long timestamp);
int 				sort_time(t_elem **ptr);
int					stockinfos(t_info *stock, int i);
int					stock_majr(t_elem **infos, t_info *stock, char *str);
int					a_option(t_elem **ptr, int i);
int					l_option(t_info *stock, t_elem **ptr);
int					ft_ls(t_info *stock, t_elem **infos);
int					rights_modes(char *str);
int					get_uid_gid(char *str, t_elem **ptr);
char				*usage_false_dir(char *str);
int					sort_in_ascii(t_elem **infos, t_info *stock, int var);
int					list_with_name(t_elem **infos, char *str, int point,
					int args);
void 				error_arg(char arg);
int					free_elems(t_elem **infos);
int					sort_args(char **argv, int i);
int					sort_args_time(char **argv, int i);
int					sort_args_reverse(char **argv, int i);
int					sort_args_time_rev(char **argv, int i);
#endif
