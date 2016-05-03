/*
** get_map.c for lol in /home/nonnen_p/CPE_2015_Lemin/src
**
** Made by paul nonnenmacher
** Login   <nonnen_p@epitech.net>
**
** Started on  Mon Apr 18 16:46:10 2016 paul nonnenmacher
** Last update Sun Apr 24 23:12:16 2016 Tristan goubeau
*/

#include "lemin.h"

bool		check_buff(t_map *map, t_room **room, char *str)
{
  map->comment = 0;
  map->room = 0;
  if (my_strncmp(str, "#", 1) != 0)
    {
      if (check_is_room(str, map) == true)
	{
	  map->room = 1;
	  if (my_put_in_list(room, map, str) == false)
	    return (false);
      	}
      else
      	if (my_put_in_tab(map, str) == false)
	  return (false);
    }
  else if (my_strncmp(str, "##", 2) == 0)
    {
      if ((check_command(map, str)) == false)
	return (false);
    }
  else if (my_strncmp(str, "#", 1) == 0)
    map->comment = 1;
  return (true);
}

bool		get_all_map(t_map *map)
{
  char		*str;
  t_room	*room;

  if ((init_room(&room) == false) || (init_tab(map) == false))
    return (false);
  while ((str = get_next_line(0)) != NULL)
    {
      str = epur_str(str);
      if ((map->command_end > 1) || (map->command_start > 1))
	break;
      if (check_buff(map, &room, str) == false)
	break;
      if (map->comment != 1 && map->room == 1)
	if ((map->map = my_strcpy(map->map, str)) == NULL)
	  return (false);
      free(str);
    }
  if ((prepare_link_tabs(&room, map) == false) ||
      (put_link_in_list(map, &room) == false))
    return (false);
  return (true);
}

bool	get_ants(t_map *map)
{
  char	*str;

  map->start = 0;
  map->end = 0;
  map->command_start = 0;
  map->command_end = 0;
  if ((str = get_next_line(0)) == NULL)
    return (false);
  if ((map->ant = my_getnbr(str)) <= 0)
    return (false);
  return (true);
}
