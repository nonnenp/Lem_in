/*
** check_room.c for check_room in /home/thoma_c/rendu/CPE_2015_Lemin/src
**
** Made by Clement Thomas
** Login   <thoma_c@epitech.net>
**
** Started on  Sat Apr 23 15:22:17 2016 Clement Thomas
** Last update Mon Apr 25 15:58:15 2016 Clement Thomas
*/

#include "lemin.h"

int	len_room(t_map *map)
{
  int	i;

  i = 0;
  while (map->links[i])
    i++;
  return (i * 2);
}

char	**stock_room_link_next(char **new_tab, t_map *map,
			       int i, int j)
{
  int	k;
  int	p;

  k = 0;
  while (map->links[++i])
    {
      j = 0;
      p = 0;
      if ((new_tab[k] = malloc(sizeof(char) *
			       (my_strlen(map->links[i]) + 1))) == NULL)
	return (NULL);
      while (map->links[i][j] != '-')
	new_tab[k][p++] = map->links[i][j++];
      new_tab[k++][p] = '\0';
      if ((new_tab[k] = malloc(sizeof(char) *
			       (my_strlen(map->links[i]) + 1))) == NULL)
	return (NULL);
      p = 0;
      j++;
      while (map->links[i][j])
	new_tab[k][p++] = map->links[i][j++];
      new_tab[k++][p] = '\0';
    }
  new_tab[k] = NULL;
  return (new_tab);
}

char	**stock_room_link(t_map *map)
{
  char	**new_tab;

  if ((new_tab = malloc(sizeof(char *) * (len_room(map) + 2))) == NULL)
    return (NULL);
  if ((new_tab = stock_room_link_next(new_tab, map, -1, 0)) == NULL)
    return (NULL);
  return (new_tab);
}

bool		check_room(t_room *room, char **tab)
{
  t_room	*tmp;
  int		i;

  i = 0;
  while (tab[i])
      {
	tmp = room;
	while (tmp->next != NULL)
	  {
	    if ((my_strcmp(tab[i], tmp->name)) == 0)
	      break ;
	    tmp = tmp->next;
	  }
	if ((my_strcmp(tab[i], tmp->name)) != 0)
	  return (false);
	i++;
      }
  return (true);
}
