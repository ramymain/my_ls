/*
** my_ls.h for my_ls in /home/ferjanr
**
** Made by FERJANI Ramy
** Login   <ferjan_r@etna-alternance.net>
**
** Started on  Mon Feb 29 11:44:33 2016 FERJANI Ramy
** Last update Thu Mar  3 18:50:08 2016 FERJANI Ramy
*/

#include <dirent.h>

#ifndef __MY_LS_H__
#define __MY_LS_H__

typedef struct	Element
{
  char			option;
  void			(*func)(int, char **);
  struct Element	*nxt;
}			Element;

typedef struct	Liste
{
  Element	*first;
}		Liste;

typedef struct	Element_mot
{
  char			*mot;
  struct Element_mot	*nxt;
}			Element_mot;

typedef struct	Liste_mot
{
  Element_mot	*first;
}		Liste_mot;

void		my_putchar(char c);
void		my_putstr(char *str);
void		my_put_nbr(int i);
void		default_ls(int argc, char **argv);
void		option_a(int argc, char **argv);
void		option_A(int argc, char **argv);
void		option_d(int argc, char **argv);
void		option_l(int argc, char **argv);
void		option_r(int argc, char **argv);
void		display_list(DIR *dir);
Liste		*init_list();
Liste_mot	*init_list_mot();
void		insert_option(Liste *liste, void (*ptrfonction)(int, char **), char option);
void		insert_mot(Liste_mot *liste_mot, char *mot);
int		my_strcmp(char *s1, char *s2);

#endif
