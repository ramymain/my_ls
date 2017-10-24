/*
** func_option_a.c for my_ls in /home/ferjanr
**
** Made by FERJANI Ramy
** Login   <ferjan_r@etna-alternance.net>
**
** Started on  Mon Feb 29 16:02:04 2016 FERJANI Ramy
** Last update Fri Mar  4 11:28:15 2016 FERJANI Ramy
*/

#include <dirent.h>
#include <sys/types.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include "my_ls.h"

void	option_a(int argc, char **argv)
{
  DIR	*dir;
  char	path[PATH_MAX + 1];
  int	i;

  i = 2;
  getcwd(path, PATH_MAX);
  if (argc == 2)
    display_list(dir = opendir(path));
  else
    while (argv[i])
      {
	if (argv[i][0] != '-')
	  {
	    if ((dir = opendir(argv[i])) != NULL)
	      display_list(dir);
	  }
	++i;
      }
  closedir(dir);
}
