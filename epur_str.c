/*
** epur_str.c for epur_str in /home/thoma_c/rendu/CPE_2015_Lemin/src
**
** Made by Clement Thomas
** Login   <thoma_c@epitech.net>
**
** Started on  Sat Apr 23 20:23:59 2016 Clement Thomas
** Last update Sun Apr 24 05:09:30 2016 Clement Thomas
*/

#include "lemin.h"

char	*epur_str(char *str)
{
  int	i;
  int	j;
  char	*epur;

  if ((epur = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while ((str[i] == ' ') || (str[i] == '\t'))
    i++;
  while (str[i])
    {
      if ((str[i] == ' ') || (str[i] == '\t'))
	{
	  epur[j++] = ' ';
	  i++;
	  while (((str[i] == ' ') || (str[i] == '\t')) && str[i])
	    i++;
	}
      epur[j++] = str[i++];
    }
  epur[j] = '\0';
  if ((epur[j - 1] == ' ') || (epur[j - 1] == '\t'))
    epur[--j] = '\0';
  return (epur);
}
