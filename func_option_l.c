/*
** func_option_l.c for quit in /home/ferjanr/rendu
**
** Made by FERJANI Ramy
** Login   <ferjan_r@etna-alternance.net>
**
** Started on  Wed Mar  2 19:34:10 2016 FERJANI Ramy
** Last update Fri Mar  4 16:58:29 2016 FERJANI Ramy
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "my_ls.h"

void	convert_time2(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] == ':')
	{
	  ++j;
	}
      if (i > 3 && j < 2)
	my_putchar(str[i]);
      ++i;
    }
  my_putchar(' ');
}

void	convert_time(char *str)
{
  int	i;
  int	p;
  int	j;

  i = 0;
  j = 0;
  p = 0;
  while(str[i])
    {
      if (str[i] == ':')
	{
	  ++j;
	}
      if (i > 3 && j < 2)
	++p;
      ++i;
    }
  convert_time2(str);
}


void	display_perms2(struct stat fileStat, struct dirent *entry)
{
  struct passwd	*pwd;
  struct group	*grp;
  int		nlink;
  int		size;

  nlink = fileStat.st_nlink;
  my_put_nbr(nlink);
  my_putstr(" ");
  if ((pwd = getpwuid(fileStat.st_uid)) != NULL)
    my_putstr(pwd->pw_name);
  my_putstr(" ");
  if ((grp = getgrgid(fileStat.st_gid)) != NULL)
    my_putstr(grp->gr_name);
  my_putstr(" ");
  size = fileStat.st_size;
  my_put_nbr(size);
  my_putstr(" ");
  convert_time(ctime(&fileStat.st_mtime));
  my_putstr(entry->d_name);
  my_putstr("\n");
}

void	display_perms(DIR *dir)
{
  struct stat	fileStat;
  struct dirent	*entry;

  while ((entry = readdir(dir)) != NULL)
    {
      if ((stat(entry->d_name, &fileStat) != 1 )
	  && entry->d_name[0] != '.')
	{
	  my_putstr((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
	  my_putstr((fileStat.st_mode & S_IRUSR) ? "r" : "-");
	  my_putstr((fileStat.st_mode & S_IWUSR) ? "w" : "-");
	  my_putstr((fileStat.st_mode & S_IXUSR) ? "x" : "-");
	  my_putstr((fileStat.st_mode & S_IRGRP) ? "r" : "-");
	  my_putstr((fileStat.st_mode & S_IWGRP) ? "w" : "-");
	  my_putstr((fileStat.st_mode & S_IXGRP) ? "x" : "-");
	  my_putstr((fileStat.st_mode & S_IROTH) ? "r" : "-");
	  my_putstr((fileStat.st_mode & S_IWOTH) ? "w" : "-");
	  my_putstr((fileStat.st_mode & S_IXOTH) ? "x" : "-");
	  my_putstr(" ");
	  display_perms2(fileStat, entry);
	}
    }
}

void	option_l(int argc, char **argv)
{
  DIR	*dir;
  char	path[PATH_MAX + 1];
  int	i;

  i = 2;
  getcwd(path, PATH_MAX);
  if (argc == 2)
    display_perms(dir = opendir(path));
  else
    while (argv[i])
      {
	if (argv[i][0] != '-')
	  {
	    if ((dir = opendir(argv[i])) != NULL)
	      display_perms(dir);
	  }
	++i;
      }
  closedir(dir);
}
