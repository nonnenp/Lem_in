##
## Makefile for MERGEEEEEEEEEEEEEEEEEEEEEE in /home/nonnen_p/CPE_2015_Lemin
##
## Made by paul nonnenmacher
## Login   <nonnen_p@epitech.net>
##
## Started on  Mon Apr 18 16:44:23 2016 paul nonnenmacher
## Last update Tue May  3 18:08:44 2016 paul nonnenmacher
##

CC	=	gcc

SRC	=	my_print.c		\
		get_next_line.c	\
		my_getnbr.c		\
		main.c		\
		tools.c		\
		get_map.c		\
		get_next.c		\
		disp.c		\
		list.c		\
		check.c		\
		put_link_in_list.c	\
		free_functions.c	\
		put_in_tab.c	\
		manage_tab.c	\
		my_list_size.c	\
		algo.c		\
		fill_map.c		\
		change_ant.c	\
		check_command.c	\
		check_room.c	\
		epur_str.c

OBJ	= $(SRC:.c=.o)

NAME	= lem_in

CFLAGS	=	-W -Wall -ansi -pedantic -Wextra

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

cl: all clean
