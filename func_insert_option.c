/*
** func_insert_option.c for my_ls in /home/ferjanr/rendu
**
** Made by FERJANI Ramy
** Login   <ferjan_r@etna-alternance.net>
**
** Started on  Tue Mar  1 15:47:10 2016 FERJANI Ramy
** Last update Wed Mar  2 15:16:32 2016 FERJANI Ramy
*/

#include <stdio.h>

#include <stdlib.h>
#include "my_ls.h"

void	insert_option(Liste *liste, void (*ptrfonction)(int, char **), char option)
{
  Element *new = malloc(sizeof(*new));

  new->func = ptrfonction;
  new->option = option;
  new->nxt = liste->first;
  liste->first = new;
}

void	insert_mot(Liste_mot *liste_mot,char *mot)
{
  Element_mot *new = malloc(sizeof(*new));

  new->mot = mot;
  new->nxt = liste_mot->first;
  liste_mot->first = new;
}
