/*
** tools.c for tools.c in /home/goubea_t/CPE_Project/CPE_2015_lemin
**
** Made by Tristan goubeau
** Login   <goubea_t@epitech.net>
**
** Started on  Thu Mar 31 16:14:05 2016 Tristan goubeau
** Last update Wed Apr 20 14:26:53 2016 Tristan goubeau
*/

#include "lemin.h"

char	*my_strdup(char *str)
{
  int	len;
  char	*dest;
  int	i;

  i = 0;
  if ((len = my_strlen(str)) == 0)
    return (NULL);
  if ((dest = malloc(len + 1)) == NULL)
    return (NULL);
  while (str[i])
    {
      dest[i] = str[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

bool	is_there_link(char *name, char *link)
{
  int	i;
  int	a;
  char	*first;
  char	*second;

  a = 0;
  i = 0;
  if ((first = malloc(my_strlen(link) + 1)) == NULL)
    return (false);
  if ((second = malloc(my_strlen(link) + 1)) == NULL)
    return (false);
  while (link && link[i] && link[i] != '-')
    {
      first[i] = link[i];
      i++;
    }
  first[i] = '\0';
  if (link && link[i] && link[i] == '-')
    i++;
  while (link && link[i])
    second[a++] = link[i++];
  second[a] = '\0';
  if (my_strcmp(name, first) == 0 || my_strcmp(name, second) == 0)
    return (true);
  return (false);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1 && s1[i] && s2 && s2[i])
    {
      if (i == n)
        return (0);
      if (s1[i] == s2[i])
        i = i + 1;
      else
        return (s1[i] - s2[i]);
    }
  if (i != n)
    return (1);
  return (0);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1 && s1[i] && s2 && s2[i])
    {
      if (s1[i] == s2[i])
        i = i + 1;
      else
        return (s1[i] - s2[i]);
      if (i == my_strlen(s1))
        return (-s2[i]);
      if (i == my_strlen(s2))
        return (s1[i]);
    }
  return (0);
}


int	my_strcmpint(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (!s1 || !s2)
    return (1);
  while (s1[i] && s2[i])
    {
      if (s1[i] != s2[i] && s1[i] > s2[i])
	return (1);
      i++;
    }
  if (s1[i] != s2[i])
    return (1);
  return (0);
}
