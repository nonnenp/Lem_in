/*
** main.c for main in /home/goubea_t/CPE_Project/CPE_2015_lemin
**
** Made by Tristan goubeau
** Login   <goubea_t@epitech.net>
**
** Started on  Thu Mar 31 16:12:56 2016 Tristan goubeau
** Last update Sun Apr 24 23:49:57 2016 Tristan goubeau
*/

#include "lemin.h"

int	main(int ac, char **av)
{
  t_map	map;

  ac = ac;
  av = av;
  if (get_ants(&map) == false)
    return (EXIT_FAILURE);
  if (get_all_map(&map) == false)
    {
      if (map.ant != 0)
	{
	  my_putnbr(map.ant);
	  my_putchar('\n');
	}
      if (map.map != NULL)
	{
	  my_putstr(map.map);
	  my_putchar('\n');
	}
      my_showtab(map.links);
      return (EXIT_FAILURE);
    }
  free(map.map);
  free_char_tab(map.links);
  return (0);
}
