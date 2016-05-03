/*
** put_link_in_list.c for put_link_in_list.c in /home/goubea_t/CPE_Project/CPE_2015_lemin
**
** Made by Tristan goubeau
** Login   <goubea_t@epitech.net>
**
** Started on  Wed Apr  6 14:52:24 2016 Tristan goubeau
** Last update Sat Apr 23 15:27:18 2016 Tristan goubeau
*/

#include "lemin.h"

int	where_is_link(char *name, char *link)
{
  int	i;

  i = 0;
  if (my_strncmp(name, link, my_strlen(name)) == 0)
    return (0);
  while (link[i] && link[i++] != '-');
  if (my_strncmp(name, &link[i], my_strlen(name)) == 0)
    return (1);
  return (-1);
}

bool	put_link_in_room_next(t_room *room, char *link, char **tab, int a)
{
  int	i;

  i = 0;
 if (where_is_link(room->name, link) == 0)
    {
      while (link[i] && link[i++] != '-');
      if ((tab[a++] = my_strdup(&link[i])) == false)
	return (false);
      tab[a] = NULL;
    }
  else if (where_is_link(room->name, link) > 0)
    {
      if ((tab[a] = malloc(my_strlen(link) + 1)) == NULL)
	return (false);
      while (link[i] && link[i] != '-')
	{
	  tab[a][i] = link[i];
	  i++;
	}
      tab[a++][i] = '\0';
      tab[a] = NULL;
    }
  else
    return (false);
 return (true);
}

bool	put_link_in_room(t_room *room, char *link)
{
  int	size;
  char	**tab;
  int	a;

  a = -1;
  size = 1;
  if (room->link)
    size = tab_size(room->link);
  if ((tab = malloc(sizeof(char *) * (size + 2))) == NULL)
    return (false);
  while (room->link[++a])
    if ((tab[a] = my_strdup(room->link[a])) == false)
      return (false);
  if (put_link_in_room_next(room, link, tab, a) == false)
    return (false);
  if (room->link)
    free_char_tab(room->link);
  room->link = tab;
  return (true);
}

bool	put_link_in_list(t_map *map, t_room **room)
{
  t_room	*tmp;
  int		a;

  if ((map->command_end != 1) || (map->command_start != 1) || map->pipe == 0)
    return (false);
  tmp = *room;
  while (tmp != NULL)
    {
      a = 0;
      while (map->links[a])
	{
	  if (is_there_link(tmp->name, map->links[a]) == true)
	    {
	      if (put_link_in_room(tmp, map->links[a]) == false)
		return (false);
	    }
	  a++;
	}
      tmp = tmp->next;
    }
  if (my_algo(*room, map) == -1)
    return (false);
  return (true);
}
