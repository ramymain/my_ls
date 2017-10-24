/*
** my_putstr.c for my_ls in /home/ferjanr
** 
** Made by FERJANI Ramy
** Login   <ferjan_r@etna-alternance.net>
** 
** Started on  Mon Feb 29 11:49:14 2016 FERJANI Ramy
** Last update Mon Feb 29 11:50:15 2016 FERJANI Ramy
*/

#include <unistd.h>
#include "my_ls.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (*(str + i) != 0)
    {
      my_putchar(*(str + i));
      i += 1;
    }
}
