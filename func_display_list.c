/*
** func_display_list.c for my_ls in /home/ferjanr
**
** Made by FERJANI Ramy
** Login   <ferjan_r@etna-alternance.net>
**
** Started on  Mon Feb 29 18:22:28 2016 FERJANI Ramy
** Last update Thu Mar  3 15:51:18 2016 FERJANI Ramy
*/

#include <dirent.h>
#include <stdlib.h>
#include "my_ls.h"

void	display_list(DIR *dir)
{
  Liste_mot *liste_mot = init_list_mot();
  struct dirent	*entry;
  char *tmp;

  while ((entry = readdir(dir)) != NULL)
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
