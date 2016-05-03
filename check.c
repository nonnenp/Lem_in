/*
** check.c for check in /home/goubea_t/CPE_Project/CPE_2015_lemin
**
** Made by Tristan goubeau
** Login   <goubea_t@epitech.net>
**
** Started on  Tue Apr  5 16:06:41 2016 Tristan goubeau
** Last update Sat Apr 23 14:25:51 2016 Tristan goubeau
*/

#include "lemin.h"

bool	check_is_room(char *str, t_map *map)
{
  int	i;

  i = 0;
  if (str)
    while (str[i])
      {
	if (str[i] == '-')
	  {
	    map->pipe++;
	    return (false);
	  }
	i++;
      }
  return (true);
}
