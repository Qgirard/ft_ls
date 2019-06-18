/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:12:04 by qgirard           #+#    #+#             */
/*   Updated: 2019/03/11 18:50:47 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft.h"

typedef struct	s_check
{
	int		diez;
	int		zero;
	int		space;
	int		less;
	int		plus;
	int		width;
	int		charzero;
	int		prec;
	char	*size;
	int		type;
	int		lenstr;
	int		sizetype;
	int		ex;
	int		sign;
	int		sshort;
	int		checkex;
	int		colour;
	int		hexaex;
	int		decimal;
	long	bigdecimal;
	double	number;
}				t_check;

typedef struct	s_excep
{
	int				x;
	struct s_excep	*next;
}				t_excep;

int				ft_printf(const char *format, ...);
int				checkoptions(const char **format, t_check **stock, va_list vl);
int				checkprecision(const char **format, t_check **stock);
int				convertinstr(char **str, t_check **stock, va_list vl,
				t_excep **current);
int				convertwidth(char **str, t_check **stock);
int				convertinstrwsize(char **str, t_check **stock, va_list vl,
				t_excep **current);
int				convertprecision(char **str, t_check **stock, va_list vl);
int				checksignerror(char **str, t_check **stock, va_list vl,
				t_excep **current);
int				convert0precision(char **str, t_check **stock, va_list vl);
int				exception(char **str, t_check **stock, va_list vl,
				t_excep **current);
int				convertprecisionerr(char **tmp, char **ptr, int rm);
int				freerror(char **str, t_check **stock, va_list vl, int i);
int				majexception(char **str, t_check **stock, va_list vl,
				t_excep **current);
int				convertfloats(char **str, t_check **stock, va_list vl);
int				lastfree(char **str, t_check **stock, t_excep **curent, int i);
int				lists(char **str, t_check **stock, t_excep **current);

#endif
