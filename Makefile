##
## Makefile for MERGEEEEEEEEEEEEEEEEEEEEEE in /home/nonnen_p/CPE_2015_Lemin
##
## Made by paul nonnenmacher
## Login   <nonnen_p@epitech.net>
##
## Started on  Mon Apr 18 16:44:23 2016 paul nonnenmacher
## Last update Mon Apr 25 14:56:23 2016 Tristan goubeau
##

HEAD	=	-I./include

CC	=	gcc $(HEAD)

SRC	=	src/my_print.c		\
		src/get_next_line.c	\
		src/my_getnbr.c		\
		src/main.c		\
		src/tools.c		\
		src/get_map.c		\
		src/get_next.c		\
		src/disp.c		\
		src/list.c		\
		src/check.c		\
		src/put_link_in_list.c	\
		src/free_functions.c	\
		src/put_in_tab.c	\
		src/manage_tab.c	\
		src/my_list_size.c	\
		src/algo.c		\
		src/fill_map.c		\
		src/change_ant.c	\
		src/check_command.c	\
		src/check_room.c	\
		src/epur_str.c

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
