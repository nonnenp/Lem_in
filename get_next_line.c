/*
** get_next_line.c for get_next_line.c in /home/goubea_t/CPE_Project/CPE_2015_lemin
**
** Made by Tristan goubeau
** Login   <goubea_t@epitech.net>
**
** Started on  Thu Mar 31 16:13:34 2016 Tristan goubeau
** Last update Wed Apr  6 16:25:48 2016 Tristan goubeau
*/

#include "get_next_line.h"

int	check_line(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\n')
        return (1);
      i++;
    }
  return (0);
}

char	*my_realloc(char *str, int nb)
{
  char	*dest;
  int	len;
  int	a;

  a = 0;
  len = my_strlen(str);
  if ((dest = malloc(sizeof(char) * (len + nb) + 1)) == NULL)
    return (NULL);
  while (str[a])
    {
      dest[a] = str[a];
      a++;
    }
  dest[a] = '\0';
  free(str);
  return (dest);
}
void	get_space(t_line *line, char *buff, int *i)
{
  while (buff[(*i)] && buff[(*i)] != '\n')
    line->str[line->a++] = buff[(*i)++];
  line->str[line->a] = '\0';
}

int	get_next(const int fd, t_line *line, char *buff, int *i)
{
  while (buff[(*i)])
    line->str[line->a++] = buff[(*i)++];
  line->str[line->a] = '\0';
  while (my_strlen(buff) > 0)
    buff[my_strlen(buff) - 1] = '\0';
  (*i) = 0;
  if ((line->r = read(fd, buff, READ_SIZE)) <= 0)
    return (1);
  buff[line->r] = '\0';
  line->str = my_realloc(line->str, READ_SIZE);
  return (0);
}

char	*get_next_line(const int fd)
{
  static char	buff[READ_SIZE + 1];
  static int	i = 0;
  t_line	line;

  if ((line.a = 0) == 0 &&
      (line.str = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  if (buff[i] == '\0')
    {
      i = 0;
      if ((line.r = read(fd, buff, READ_SIZE)) < 0)
	return (NULL);
      buff[line.r + 1] = '\0';
    }
  while (check_line(&buff[i]) == 0)
    if (get_next(fd, &line, buff, &i) == 1)
      return (NULL);
  get_space(&line, buff, &i);
  if (buff[i] == '\n' && buff[i++]);
  else
    return (NULL);
  if (!buff[i])
    while (my_strlen(buff) > 0)
      buff[my_strlen(buff) - 1] = '\0';
  return (line.str);
}
