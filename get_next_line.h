/*
** get_next_line.h for get_next_line.h in /home/goubea_t/CPE_Project/CPE_2015_lemin
**
** Made by Tristan goubeau
** Login   <goubea_t@epitech.net>
**
** Started on  Thu Mar 31 15:58:40 2016 Tristan goubeau
** Last update Wed Apr  6 16:23:03 2016 Tristan goubeau
*/

#ifndef READ_SIZE
# define READ_SIZE (1)
#endif /* !READ_SIZE */

#ifndef	GET_NEXT_LINE
# define GET_NEXT_LINE

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct		s_line
{
  char			*str;
  int			r;
  int			a;
}			t_line;

int	my_strlen(char *);
char	*my_realloc(char *, int);
char	*get_folder(int);
char	*get_next_line(const int);
int	get_next(const int, t_line *, char *, int *);
void	get_space(t_line *, char *, int *);

#endif	/* !GET_NEXT_LINE */
