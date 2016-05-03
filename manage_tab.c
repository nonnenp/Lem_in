/*
** manage_tab.c for manage_tab.c in /home/goubea_t/CPE_Project/CPE_2015_lemin
**
** Made by Tristan goubeau
** Login   <goubea_t@epitech.net>
**
** Started on  Tue Apr  5 16:36:26 2016 Tristan goubeau
** Last update Sun Apr 24 16:10:07 2016 Tristan goubeau
*/

#include "lemin.h"

char	*my_strcpy(char *s1, char *s2)
{
  int	i;
  int	len;
  char	*dest;
  int	a;

  a = 0;
  i = 0;
  len = my_strlen(s1) + my_strlen(s2) + 2;
  if ((dest = malloc(len)) == NULL)
    return (NULL);
  while (s1 && s1[i])
    {
      dest[i] = s1[i];
      i++;
    }
  if (i > 0)
    dest[i++] = '\n';
  while (s2 && s2[a])
    dest[i++] = s2[a++];
  dest[i] = '\0';
  free(s1);
  return (dest);
}

void	get_real_first(t_room **room)
{
  t_room	*tmp;
  t_room	*first;

  tmp = *room;
  tmp->prev = NULL;
  first = tmp;
  while (tmp != NULL)
    {
      tmp->first = first;
      tmp = tmp->next;
    }
}

bool	prepare_link_tabs(t_room **room, t_map *map)
{
  t_room	*tmp;
  char		**tab;

  if (del_in_front(room) == false)
    return (NULL);
  if ((check_room(*room, tab = stock_room_link(map))) == false)
    return (false);
  free_char_tab(tab);
  get_real_first(room);
  tmp = *room;
  while (tmp != NULL)
    {
      if ((tmp->link = malloc(sizeof(char *))) == NULL)
	return (false);
      tmp->link[0] = NULL;
      tmp = tmp->next;
    }
  return (true);
}

int	tab_size(char **tab)
{
  int	count;
  int	a;

  a = 0;
  count = 0;
  if (tab)
    while (tab[a])
      {
	count++;
	a++;
      }
  return (count);
}
