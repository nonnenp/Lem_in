/*
** my_print.c for myprint in /home/nonnen_p/Rush1/step_1
**
** Made by paul nonnenmacher
** Login   <nonnen_p@epitech.net>
**
** Started on  Fri Jan  8 21:57:35 2016 paul nonnenmacher
** Last update Thu Mar 31 16:01:45 2016 Tristan goubeau
*/

#include "lemin.h"

int	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int	my_putcharerror(char c)
{
  if (write(2, &c, 1) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int	my_putstr(char *str)
{
  if (str)
    {
      while (*str)
	{
	  if (my_putchar(*str++) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int	my_putstrerror(char *str)
{
  if (str)
    {
      while (*str)
	{
	  if (my_putcharerror(*str++) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str)
    while (*str++)
      ++i;
  return (i);
}
