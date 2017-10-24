/*
** func_option_r.c for my_ls in /home/ferjanr/rendu
**
** Made by FERJANI Ramy
** Login   <ferjan_r@etna-alternance.net>
**
** Started on  Thu Mar  3 18:01:17 2016 FERJANI Ramy
** Last update Thu Mar  3 18:21:53 2016 FERJANI Ramy
*/

#include <dirent.h>
#include <sys/types.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include "my_ls.h"


void	display_list_r(DIR *dir)
{
  Liste_mot *liste_mot = init_list_mot();
  struct dirent	*entry;
  char *tmp;

  while ((entry = readdir(dir)) != NULL)
    if (entry->d_name[0] != '.')
      insert_mot(liste_mot, entry->d_name);
  Element_mot *actuel = liste_mot->first;
  while (actuel->nxt->nxt != NULL)
    {
      if ((my_strcmp(actuel->mot, actuel->nxt->mot)) < 0)
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

void	option_r(int argc, char **argv)
{
  DIR	*dir;
  char	path[PATH_MAX + 1];
  int	i;

  i = 1;
  getcwd(path, PATH_MAX);
  if (argc == 2)
    {
      if ((dir = opendir(path)) != NULL)
	display_list_r(dir);
    }
  else
    {
      while (argv[i])
	{
	  if ((dir = opendir(argv[i])) != NULL)
	    display_list_r(dir);
	  ++i;
	}
    }
  closedir(dir);
}
