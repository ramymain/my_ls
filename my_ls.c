/*
** my_ls.c for my_ls in /home/ferjanr
**
** Made by FERJANI Ramy
** Login   <ferjan_r@etna-alternance.net>
**
** Started on  Mon Feb 29 11:14:24 2016 FERJANI Ramy
** Last update Fri Mar  4 11:31:51 2016 FERJANI Ramy
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <getopt.h>
#include "my_ls.h"

int	main(int argc, char **argv)
{
  int		option;
  Liste *liste = init_list();
  Element *actuel = liste->first;

  if ((argc >= 2 && argv[1][0] != '-') || (argc == 1))
    default_ls(argc, argv);
  else
    {
      while ((option = getopt(argc, argv, "lRrdtaAL")) != -1)
	{
	  while (actuel->nxt != NULL)
	    {
	      if (actuel->option == option)
		  actuel->func(argc, argv);
	      actuel = actuel->nxt;
	    }
	}
    }
  return (0);
}
