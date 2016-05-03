/*
** my_getnbr.c for getnbr in /home/goubea_t/CPE_Project/CPE_2015_lemin
**
** Made by Tristan goubeau
** Login   <goubea_t@epitech.net>
**
** Started on  Thu Mar 31 15:59:01 2016 Tristan goubeau
** Last update Sun Apr 24 23:05:10 2016 Tristan goubeau
*/

#include "lemin.h"

void	my_showtab(char **tab)
{
  int	i;

  i = 0;
  if (tab)
    while (tab[i])
      {
	my_putstr(tab[i]);
	my_putchar(10);
	i++;
      }
}

int	check_max(char *str)
{
  int	i;

  i = 0;
  while (str[i] && str[i] == '-')
    i++;
  if (my_strlen(&str[i]) < 10)
    return (0);
  else
    {
      if (my_strcmpint(&str[i], "2147483647") == 1)
	return (1);
      else
	return (0);
    }
}

int	check(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] < '0' || str[i] > '9'))
	return (1);
      i++;
    }
  if (my_strlen(str) > 11)
    return (1);
  else if (my_strlen(str) == 11)
    if (check_max(str) == 1)
      return (1);
  return (0);
}

int	my_getnbr(char *str)
{
  int	res;
  int	i;
  int	count;
  int	neg;

  neg = 1;
  count = 0;
  res = 0;
  i = 0;
  if (check(str) == 1)
    return (-1);
  while (str[i] && (str[i] < '0' || str[i] > '9'))
    if (str[i++] == '-')
      count++;
  if (count % 2 != 0)
    neg = -1;
  while (str[i] && str[i] != '\n')
    {
      res = res + str[i] - '0';
      if (str[i] && str[i + 1] && str[i + 1] != '\n')
        res = res * 10;
      i++;
    }
  return (res * neg);
}
