/*
** func_option_d.c for my_ls in /home/ferjanr/rendu
**
** Made by FERJANI Ramy
** Login   <ferjan_r@etna-alternance.net>
**
** Started on  Thu Mar  3 16:45:12 2016 FERJANI Ramy
** Last update Fri Mar  4 09:08:27 2016 FERJANI Ramy
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include "my_ls.h"

void	option_d(int argc, char **argv)
{
  struct stat	info;
  int	i;

  i = 2;
  if (argc == 2)
    {
      my_putchar('.');
    }
  else
    {
      while (argv[i])
	{
	  if (lstat(argv[i], &info) != -1)
	    {
	      my_putstr(argv[i]);
	      my_putstr(" ");
	    }
	  ++i;
	}
    }
  my_putchar('\n');
}
