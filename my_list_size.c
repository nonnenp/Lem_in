/*
** my_list_size.c for my_list_size.c in /home/goubea_t/CPE_Project/CPE_2015_lemin
**
** Made by Tristan goubeau
** Login   <goubea_t@epitech.net>
**
** Started on  Mon Apr  4 12:23:52 2016 Tristan goubeau
** Last update Mon Apr  4 12:38:54 2016 Tristan goubeau
*/

#include "lemin.h"

int	my_list_size(t_room *begin)
{
  int		count;
  t_room	*tmp;

  count = 0;
  tmp = begin;
  while (tmp != NULL)
    {
      count = count + 1;
      tmp = tmp->next;
    }
  return (count);
}
