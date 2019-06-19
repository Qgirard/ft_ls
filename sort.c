/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:14:37 by qgirard           #+#    #+#             */
/*   Updated: 2019/06/19 22:41:41 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		elems_sorted(t_elem **ptr)
{
	while (*ptr && (*ptr)->next)
	{
		if ((ft_strcmp((*ptr)->name, (*ptr)->next->name) > 0
		&& (*ptr)->in_dir == (*ptr)->next->in_dir && (*ptr)->type != 1
		&& (*ptr)->type != -1) || ((*ptr)->in_dir > (*ptr)->next->in_dir))
			return (1);
		(*ptr) = (*ptr)->next;
	}
	return (0);
}

void	swap_strings(t_elem **ptr)
{
	char	*tmp;

	tmp = (*ptr)->next->name;
	(*ptr)->next->name = (*ptr)->name;
	(*ptr)->name = tmp;
	tmp = (*ptr)->next->name_dir;
	(*ptr)->next->name_dir = (*ptr)->name_dir;
	(*ptr)->name_dir = tmp;
}

int		place_dir_end(t_elem **infos)
{
	t_elem	*ptr;

	ptr = (*infos);
	while (ptr)
	{
		if (ptr->in_dir > 0)
		{
			while (ptr && ptr->next && ptr->in_dir == ptr->next->in_dir)
			{
				ft_swap(&(ptr->type), &(ptr->next->type));
				ft_swap(&(ptr->in_dir), &(ptr->next->in_dir));
				swap_strings(&ptr);
				ptr = ptr->next;
			}
		}
		ptr = ptr->next;
	}
	return (1);
}

int		sort_in_ascii(t_elem **infos, t_info *stock, int var)
{
	t_elem	*ptr;

	var = 0;
	ptr = (*infos);
	while (elems_sorted(&ptr))
	{
		while (ptr && ptr->next)
		{
			if (ptr && ptr->next && ((ft_strcmp(ptr->name, ptr->next->name) > 0
			&& ptr->in_dir == ptr->next->in_dir && ptr->type != 1
			&& ptr->type != -1) || ptr->in_dir > ptr->next->in_dir))
			{
				ft_swap(&(ptr->type), &(ptr->next->type));
				ft_swap(&(ptr->in_dir), &(ptr->next->in_dir));
				swap_strings(&ptr);
			}
			ptr = ptr->next;
		}
		ptr = (*infos);
	}
	if (stock->r && stock->j > 0)
		place_dir_end(infos);
	return (1);
}

int 	sort_time(t_elem **ptr)
{
	t_elem	*tmp;
	char 	*name;

	name = NULL;
	tmp = (*ptr);
	while(tmp && tmp->next)
	{
		if(tmp && tmp->next
		&& get_timestamp(tmp->name) < get_timestamp(tmp->next->name))
		{
			name = tmp->name;
			tmp->name = tmp->next->name;
			tmp->next->name = name;
		}
		tmp = tmp->next;
	}
	tmp = (*ptr);
	return(1);
}
