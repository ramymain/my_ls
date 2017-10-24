/*
** func_init_list.c for my_ls in /home/ferjanr
**
** Made by FERJANI Ramy
** Login   <ferjan_r@etna-alternance.net>
**
** Started on  Tue Mar  1 10:53:59 2016 FERJANI Ramy
** Last update Thu Mar  3 18:13:42 2016 FERJANI Ramy
*/

#include <stdlib.h>
#include "my_ls.h"

Liste *init_list()
{
  Liste *liste = malloc(sizeof(*liste));
  Element *element = malloc(sizeof(*element));

  element->func = default_ls;
  element->option = 'z';
  element->nxt = NULL;
  liste->first = element;
  insert_option(liste, option_l,'l');
  insert_option(liste, option_a,'a');
  insert_option(liste, option_A,'A');
  insert_option(liste, option_d,'d');
  insert_option(liste, option_r,'r');
  return liste;
}

Liste_mot *init_list_mot()
{
  Liste_mot *liste_mot = malloc(sizeof(*liste_mot));
  Element_mot *element_mot = malloc(sizeof(*element_mot));

  element_mot->mot = "vide";
  element_mot->nxt = NULL;
  liste_mot->first = element_mot;
  return liste_mot;
}

