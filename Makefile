# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/04 16:35:29 by qgirard           #+#    #+#              #
#    Updated: 2019/06/20 23:16:10 by qgirard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = ft_ls

COMPILIB = make -C libft
CLIB = make -C libft clean
FCLIB = make -C libft fclean
LIB = libft/libft.a

HEADER = ft_ls.h

CC = gcc -o
CFLAGS = -g -Wall -Wextra -Werror
#-g3 -fsanitize=address

SRC = ft_ls.c main.c stockinfos.c a_option.c usage.c l_option.c rights_modes.c \
		get_uid_gid.c sort.c list_with_name.c free_elems.c sort_args.c \
		sort_args_reverse.c sort_args_time.c sort_args_time_rev.c \
		stock_majr.c

OBJ = $(SRC:.c=.o)

all : $(LIB) $(EXEC)

$(LIB) :
	$(COMPILIB)

$(EXEC) : $(OBJ)
	$(CC) $(EXEC) $(CFLAGS) $(SRC) $(LIB)

%.o: %.c
	@$(CC) $(CFLAGS) -c -I $(HEADER) $< -o $@

clean :
	rm -rf $(OBJ)
	$(CLIB)

fclean : clean
	rm -rf $(EXEC)
	$(FCLIB)

re : fclean all

.PHONY : all clean fclean re
