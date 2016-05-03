/*
** put_in_tab.c for put_in_tab in /home/goubea_t/CPE_Project/CPE_2015_lemin
**
** Made by Tristan goubeau
** Login   <goubea_t@epitech.net>
**
** Started on  Tue Apr  5 16:19:14 2016 Tristan goubeau
** Last update Sat Apr 23 14:25:39 2016 Tristan goubeau
*/

#include "lemin.h"

bool	init_tab(t_map *map)
{
  map->pipe = 0;
  if ((map->links = malloc(sizeof(char *) * 1)) == NULL)
    return (false);
  if ((map->map = malloc(sizeof(char) * 1)) == NULL)
    return (false);
  map->map[0] = '\0';
  map->links[0] = NULL;
  return (true);
}

bool	my_put_in_tab(t_map *map, char *str)
{
  int	len;
  char	**tab;
  int	a;

  a = 0;
  len = 1;
  if (map->links)
    len = tab_size(map->links);
  if ((tab = malloc(sizeof(char *) * (len + 2))) == NULL)
    return (false);
  if (map->links)
    while (map->links[a])
      {
	if ((tab[a] = my_strdup(map->links[a])) == NULL)
	  return (false);
	a++;
      }
  tab[a++] = my_strdup(str);
  tab[a] = NULL;
  if (map->links)
    free_char_tab(map->links);
  map->links = tab;
  return (true);
}
