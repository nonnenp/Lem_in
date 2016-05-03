/*
** change_ant.c for change_ant in /home/nonnen_p/CPE_2015_Lemin/src
** 
** Made by paul nonnenmacher
** Login   <nonnen_p@epitech.net>
** 
** Started on  Mon Apr 18 16:18:02 2016 paul nonnenmacher
** Last update Wed Apr 20 13:45:29 2016 paul nonnenmacher
*/

#include "lemin.h"

int	*change_ant(int *ant, t_map *ants, t_room *map)
{
  int	i;
  int	*new_ant;
  int	j;

  if (map->start == 1)
    i = ants->ant;
  else
    i = 1;
  if ((new_ant = malloc(sizeof(int) * i)) == NULL)
    return (NULL);
  j = 0;
  if (i > 1)
    {
      i = 1;
      while (ant && ant[i] && ant[i] != -1)
	new_ant[j++] = ant[i++];
      new_ant[j] = -1;
    }
  else
    new_ant[0] = -1;
  free(ant);
  return (new_ant);
}
