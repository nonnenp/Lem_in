/*
** disp.c for disp.c in /home/goubea_t/CPE_Project/CPE_2015_lemin
**
** Made by Tristan goubeau
** Login   <goubea_t@epitech.net>
**
** Started on  Thu Mar 31 16:09:10 2016 Tristan goubeau
** Last update Sat Apr 16 16:18:06 2016 Tristan goubeau
*/

#include "lemin.h"

void		my_show_links(t_room **room)
{
  t_room	*tmp;
  int		count;

  count = 1;
  tmp = *room;
  while (tmp != NULL)
    {
      my_putstr("room n°");
      my_putstr(tmp->name);
      my_putstr(":\n");
      my_show_tab(tmp->link);
      my_putchar(10);
      tmp = tmp->next;
      count++;
     }
}

void		my_show_tab(char **tab)
{
  int		a;

  a = 0;
  if (tab)
    while (tab[a])
      {
	my_putstr(tab[a]);
	my_putchar(10);
	a++;
      }
}

void		my_show_list(t_room **room)
{
  t_room	*tmp;

  tmp = *room;
  while (tmp != NULL)
    {
      my_putstr(tmp->name);
      my_putchar(10);
      tmp = tmp->next;
    }
}

void		my_show_list_int(t_room **room)
{
  t_room	*tmp;

  tmp = *room;
  while (tmp != NULL)
    {
      my_putnbr(tmp->start);
      my_putchar(10);
      tmp = tmp->next;
    }
}

void		my_putnbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  if (nb / 10 > 0)
    my_putnbr(nb / 10);
  my_putchar(nb % 10 + '0');
}
