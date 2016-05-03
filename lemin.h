/*
** lemin.h for lol in /home/nonnen_p/CPE_2015_Lemin
**
** Made by paul nonnenmacher
** Login   <nonnen_p@epitech.net>
**
** Started on  Mon Apr 18 16:44:46 2016 paul nonnenmacher
** Last update Sun Apr 24 23:09:36 2016 Tristan goubeau
*/

#ifndef LEMIN_H_
# define LEMIN_H_

# ifndef READ_SIZE
#  define READ_SIZE (1)
# endif /* !READ_SIZE */

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include "get_next_line.h"

typedef struct	s_room
{
  int		ppl;
  char		*name;
  int		*ant;
  char		**link;
  int		start;
  int		end;
  int		road;
  struct s_room	*next;
  struct s_room	*prev;
  struct s_room	*first;
}		t_room;

typedef struct  s_map
{
  int		ant;
  char		*map;
  char		**links;
  int		count;
  int		start;
  int		end;
  int		command_start;
  int		command_end;
  int		pipe;
  int		comment;
  int		room;
}		t_map;

typedef struct s_exode
{
  int		end;
  int		i;
  int		name;
  int		change;
}		t_exode;

/*
**outils
*/

char	*my_strdup(char *);
int	my_strncmp(char *, char *, int);
int	my_strcmp(char *, char *);
int	my_strlen(char *);
int	my_getnbr(char *);
int	my_strcmpint(char *, char *);
void	my_show_list(t_room **);
char	*my_strcpy(char *, char *);
char	*epur_str(char *);

/*
**affichage
*/

int	my_putchar(char);
int	my_putcharerror(char);
int	my_putstr(char *);
int	my_putstrerror(char *);
void	my_putnbr(int);
void	my_show_tab(char **);
void	my_show_links(t_room **);
void	my_showtab(char **);

/*
**algo
*/

t_room	*algo(t_room *, t_room *, int);
char	**way(t_room *);
int	my_algo(t_room *, t_map *);
t_room	*fill_ant(t_room *, t_map *, int, t_room *);
t_room	*fill_ppl(t_room *, t_map *);
char	**rev_way(char **);
int	*change_ant(int *, t_map *, t_room *);
t_room *algo(t_room *, t_room *, int);
void	exode(t_room *, t_map *, char **);

/*
**gestion de map
*/

bool	init_tab(t_map *);
bool	init_room(t_room **);
void	my_put_in_list_next(t_map *, t_room *);
bool	my_put_in_list(t_room **, t_map *, char *);
bool	get_all_map(t_map *);
bool	get_ants(t_map *);
bool	my_put_in_tab(t_map *, char *);
int	tab_size(char **);
bool	put_link_in_room(t_room *, char *);
bool	put_link_in_list(t_map *, t_room **);
bool	prepare_link_tabs(t_room **, t_map *);
int	where_is_link(char *, char *);
bool	is_there_link(char *, char *);

/*
**check
*/

bool	check_buff(t_map *, t_room **, char *);
bool	check_is_room(char *, t_map *);
bool	check_command(t_map *, char *);

/*
**list
*/

bool	del_in_front(t_room **);

/*
**free
*/

void	free_char_tab(char **);
void	free_list(t_room **);

/*
**check room
*/

char	**stock_room_link(t_map *);
char	**stock_room_link_next(char **, t_map *, int, int);
int	len_room(t_map *);
bool	check_room(t_room *, char **);

#endif /* LEMIN_H_ */
