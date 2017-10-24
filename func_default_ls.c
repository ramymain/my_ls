/*
** func_default_ls.c for my_ls in /home/ferjanr
**
** Made by FERJANI Ramy
** Login   <ferjan_r@etna-alternance.net>
**
** Started on  Mon Feb 29 16:06:10 2016 FERJANI Ramy
** Last update Thu Mar  3 16:30:35 2016 FERJANI Ramy
*/

#include <dirent.h>
#include <sys/types.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include "my_ls.h"


void	def_display_list(DIR *dir)
{
  Liste_mot *liste_mot = init_list_mot();
  struct dirent	*entry;
  char *tmp;

  while ((entry = readdir(dir)) != NULL)
    if (entry->d_name[0] != '.')
      insert_mot(liste_mot, entry->d_name);
  Element_mot *actuel = liste_mot->first;
  while (actuel->nxt != NULL)
    {
      if ((my_strcmp(actuel->mot, actuel->nxt->mot)) > 0)
	{
       	  tmp = actuel->mot;
	  actuel->mot = actuel->nxt->mot;
	  actuel->nxt->mot = tmp;
	  actuel = liste_mot->first;
	}
      actuel = actuel->nxt;
    }
  actuel = liste_mot->first;
  while (actuel->nxt != NULL)
    {
      my_putstr(actuel->mot);
      my_putstr("\n");
      actuel = actuel->nxt;
    }
}

void	default_ls(int argc, char **argv)
{
  DIR	*dir;
  char	path[PATH_MAX + 1];
  int	i;

  i = 1;
  getcwd(path, PATH_MAX);
  if (argc == 1)
    {
      if ((dir = opendir(path)) != NULL)
	def_display_list(dir);
    }
  else
    {
      while (argv[i])
	{
	  if ((dir = opendir(argv[i])) != NULL)
	    def_display_list(dir);
	  ++i;
	}
    }
  closedir(dir);
}
