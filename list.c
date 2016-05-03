/*
** list.c for list.c in /home/goubea_t/CPE_Project/CPE_2015_lemin
**
** Made by Tristan goubeau
** Login   <goubea_t@epitech.net>
**
** Started on  Mon Apr  4 12:25:11 2016 Tristan goubeau
** Last update Sun Apr 24 15:43:00 2016 Tristan goubeau
*/

#include "lemin.h"

bool		del_in_front(t_room **list)
{
  t_room	*tmp;
  t_room	*temp;

  if (*list != NULL && (*list)->next != NULL)
    {
      temp = *list;
      tmp = temp->next;
      *list = tmp;
      (*list)->first = *list;
    }
  else
    return (false);
  return (true);
}

bool		init_room(t_room **room)
{
  t_room	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (false);
  elem->name = my_strdup("root");
  elem->first = elem;
  elem->start = 0;
  elem->road = -1;
  elem->end = 0;
  elem->prev = NULL;
  elem->next = NULL;
  *room = elem;
  return (true);
}

void		get_prev(t_room *elem, t_room **room)
{
  t_room	*tmp;

  tmp = *room;
  if (tmp->next != NULL)
    {
      while (tmp->next->next != NULL)
	tmp = tmp->next;
      elem->prev = tmp;
    }
  else
    elem->prev = tmp;
}

void		my_put_in_list_next(t_map *map, t_room *elem)
{
  if (map->start == 1)
    elem->start = 1;
  else
    elem->start = 0;
  if (map->end == 1)
    {
      elem->end = 1;
      elem->road = 0;
    }
  else
    {
      elem->end = 0;
      elem->road = -1;
    }
  map->end = 0;
  map->start = 0;
}

bool		my_put_in_list(t_room **room, t_map *map, char *str)
{
  t_room	*elem;
  t_room	*tmp;
  int		i;

  i = 0;
  tmp = *room;
  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (false);
  if ((elem->name = malloc(my_strlen(str) + 1)) == NULL)
    return (false);
  while (str[i] && str[i] != ' ')
    {
      elem->name[i] = str[i];
      i++;
    }
  elem->name[i] = '\0';
  elem->first = tmp->first;
  elem->next = NULL;
  my_put_in_list_next(map, elem);
  get_prev(elem, room);
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = elem;
  return (true);
}
