/*
** check_command.c for check_command in /home/thoma_c/rendu/CPE_2015_Lemin/src
**
** Made by Clement Thomas
** Login   <thoma_c@epitech.net>
**
** Started on  Sun Apr 17 18:05:47 2016 Clement Thomas
** Last update Sun Apr 24 23:15:59 2016 Tristan goubeau
*/

#include "lemin.h"

bool	check_command(t_map *map, char *str)
{
  if (my_strcmp(str, "##start") == 0)
    {

      if (map->command_start < 1)
	{
	  map->room = 1;
	  map->command_start++;
	}
      else
	return (false);
      map->start = 1;
    }
  else if (my_strcmp(str, "##end") == 0)
    {
      if (map->command_end < 1)
	{
	  map->room = 1;
	  map->command_end++;
	}
      else
	return (false);
      map->end = 1;
    }
  return (true);
}
