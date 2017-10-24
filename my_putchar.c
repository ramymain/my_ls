/*
** my_putchar.c for my_ls in /home/ferjanr
** 
** Made by FERJANI Ramy
** Login   <ferjan_r@etna-alternance.net>
** 
** Started on  Mon Feb 29 11:52:08 2016 FERJANI Ramy
** Last update Mon Feb 29 11:52:13 2016 FERJANI Ramy
*/

#include <unistd.h>
#include "my_ls.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
