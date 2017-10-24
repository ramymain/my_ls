/*
** my_strcmp.c for my_ls in /home/ferjanr/rendu
**
** Made by FERJANI Ramy
** Login   <ferjan_r@etna-alternance.net>
**
** Started on  Wed Mar  2 14:33:00 2016 FERJANI Ramy
** Last update Wed Mar  2 17:27:25 2016 FERJANI Ramy
*/

#include "my_ls.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] > s2[i])
	return (s1[i] - s2[i]);
      else if (s1[i] < s2[i])
	return (s1[i] - s2[i]);
      ++i;
    }
  if (s1[i] == '\0' && s2[i] != '\0')
    return (0 - s2[i]);
  if (s2[i] == '\0' && s1[i] != '\0')
    return (0 + s1[i]);
  return (0);
}
