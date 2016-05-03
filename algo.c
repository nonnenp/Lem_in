/*
** algo.c for lol in /home/nonnen_p/CPE_2015_Lemin/src
**
** Made by paul nonnenmacher
** Login   <nonnen_p@epitech.net>
**
** Started on  Wed Apr 20 13:56:12 2016 paul nonnenmacher
** Last update Mon Apr 25 11:09:11 2016 Tristan goubeau
*/


#include "lemin.h"

int	my_algo(t_room *map, t_map *ant)
{
  char	**my_way;

  map = algo(map, map, 0);
  my_way = way(map);
  my_way = rev_way(my_way);
  map = fill_ant(map, ant, 0, map);
  map = fill_ppl(map, ant);
  map = map->first;
  while (map->start != 1)
    map = map->next;
  if (map->road == -1)
    return (-1);
  map = map->first;
  my_putnbr(ant->ant);
  my_putchar('\n');
  my_putstr(ant->map);
  my_putchar('\n');
  my_showtab(ant->links);
  exode(map, ant, my_way);
  free_list(&map);
  return (0);
}

char	*get_new_elem_road(t_room *map, t_room *tmp, int j)
{
  j = 0;
  tmp = map->first;
  while (map->link && map->link[j])
    {
      while (my_strcmp(map->link[j], tmp->name) != 0)
	tmp = tmp->next;
      if (tmp->road == map->road - 1)
	return (tmp->name);
      else
	{
	  ++j;
	  tmp = map->first;
	}
    }
  return (NULL);
}

 char		**way(t_room *map)
{
  int		nb;
  char		**way;
  int		i;
  t_room	*tmp;
  int		j;

  tmp = map;
  j = 0;
  while (map->start != 1)
    map = map->next;
  i = 0;
  nb = map->road + 2;
  if ((way = malloc(sizeof(char *) * (nb + 1))) == NULL)
    return (NULL);
  way[i++] = my_strdup(map->name);
  while (map->road > 0)
    {
      way[i] = my_strdup(get_new_elem_road(map, tmp, j));
      map = map->first;
      while (my_strcmp(way[i], map->name) != 0)
	map = map->next;
      ++i;
    }
  way[i] = NULL;
  return (way);
}

t_room		*algo(t_room *map, t_room *tmp, int change)
{
  int		i;

  while (tmp != NULL)
    {
      if (tmp->road != -1)
	{
	  i = 0;
	  while (tmp->link && tmp->link[i])
	    {
	      while (my_strcmp(tmp->link[i], map->name) != 0)
		map = map->next;
	      if ((map->road == -1 || map->road > tmp->road + 1))
		{
		  map->road = tmp->road + 1;
		  change = 1;
		}
	      map = map->first;
	      ++i;
	    }
	}
      if (change == 1)
	algo(map, map, 0);
      tmp = tmp->next;
    }
  return (map);
}
