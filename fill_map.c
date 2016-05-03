/*
** fill_map.c for fillmap in /home/nonnen_p/CPE_2015_Lemin/src
**
** Made by paul nonnenmacher
** Login   <nonnen_p@epitech.net>
**
** Started on  Mon Apr 18 15:02:53 2016 paul nonnenmacher
** Last update Sat Apr 23 15:22:37 2016 Tristan goubeau
*/

#include "lemin.h"

char	**rev_way(char **my_way)
{
  char	**new_way;
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (my_way && my_way[i])
    ++i;
  if ((new_way = malloc(sizeof(char *) * (i + 1))) == NULL)
    return (NULL);
  --i;
  while (i >= 0)
    new_way[j++] = my_strdup(my_way[i--]);
  new_way[j] = NULL;
  free(my_way);
  return (new_way);
}

t_room	*fill_ant(t_room *map, t_map *ant, int i, t_room *tmp)
{
  while (map != NULL)
    {
      if (map->start == 1)
	{
	  if ((map->ant = malloc(sizeof(int) * (ant->ant + 1))) == NULL)
	    return (NULL);
	  while (i < ant->ant)
	    {
	      map->ant[i] = i + 1;
	      ++i;
	    }
	  map->ant[i] = -1;
	}
      else
	{
	  if ((map->ant = malloc(sizeof(int))) == NULL)
	    return (NULL);
	  map->ant[0] = -1;
	}
      map = map->next;
    }
  map = tmp;
  return (map);
}

t_room	*fill_ppl(t_room *map, t_map *ant)
{
  while (map->next != NULL)
    {
      if (map->start == 1)
	map->ppl = ant->ant;
      else
	map->ppl = 0;
      map = map->next;
    }
  if (map->start == 1)
    map->ppl = ant->ant;
  else
    map->ppl = 0;
  map = map->first;
  return (map);
}

t_exode	change_travel(t_room **map, t_exode travel, t_map *ant, char **my_way)
{
  --(*map)->ppl;
  travel.name = (*map)->ant[0];
  (*map)->ant = change_ant((*map)->ant, ant, *map);
  *map = (*map)->first;
  while (my_strcmp(my_way[travel.i - 1], (*map)->name) != 0)
    *map = (*map)->next;
  if ((*map)->end == 1)
    ++travel.end;
  if (travel.change == 1)
    my_putchar(' ');
  my_putchar('P');
  my_putnbr(travel.name);
  my_putchar('-');
  my_putstr((*map)->name);
  travel.change = 1;
  return (travel);
}

void	exode(t_room *map, t_map *ant, char **my_way)
{
  t_exode	travel;

  travel.end = 0;
  while (travel.end < ant->ant)
    {
      travel.i = 1;
      travel.change = 0;
      while (my_way && my_way[travel.i])
	{
	  map = map->first;
	  while (my_strcmp(my_way[travel.i], map->name) != 0)
	    map = map->next;
	  if (map->ppl != 0)
	    {
	      travel = change_travel(&map, travel, ant, my_way);
	      ++map->ppl;
	      map->ant[0] = travel.name;
	    }
	  ++travel.i;
	}
      my_putchar('\n');
    }
}
