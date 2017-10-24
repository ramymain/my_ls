/*
** my_put_nbr.c for my_put_nbr in /home/ferjanr/rendu
**
** Made by FERJANI Ramy
** Login   <ferjan_r@etna-alternance.net>
**
** Started on  Thu Mar  3 10:47:07 2016 FERJANI Ramy
** Last update Thu Mar  3 18:29:58 2016 FERJANI Ramy
*/

#include "my_ls.h"

void	my_put_nbr(int	n)
{
  int	i;
  i = 1;
  if (n == -2147483648)
    my_putstr("-2147483678");
  if (n < 0)
    {
      my_putchar('-');
      n = -n;
    }
  while ((n / i) >= 10)
    i *= 10;
  while (i > 0)
    {
      my_putchar((n / i) % 10 + 48);
      i /= 10;
    }
}
