/*
** free_functions.c for free_functions.c in /home/goubea_t/CPE_Project/CPE_2015_lemin
**
** Made by Tristan goubeau
** Login   <goubea_t@epitech.net>
**
** Started on  Tue Apr  5 16:31:48 2016 Tristan goubeau
** Last update Wed Apr 20 15:03:21 2016 Tristan goubeau
*/

#include "lemin.h"

void	free_list(t_room **room)
{
  t_room	*tmp;
  t_room	*next;

  tmp = *room;
  while (tmp != NULL)
    {
      next = tmp->next;
      free(tmp);
      tmp = next;
    }
}

void	free_char_tab(char **tab)
{
  int	a;

  a = 0;
  if (tab)
    while (tab[a])
      {
	free(tab[a]);
	a++;
      }
  if (tab)
    free(tab);
}
