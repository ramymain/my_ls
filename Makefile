##
## Makefile for my_ls in /home/ferjan_r/
##
## Made by FERJANI Ramy
## Login   <ferjan_r@etna-alternance.net>
##
## Started on  Sat Feb 29 11:34:32 2016 FERJANI Ramy
## Last update Thu Mar  3 18:13:26 2016 FERJANI Ramy
##

NAME	=	my_ls
CC	=	gcc
SRC	=	my_ls.c \
		my_putstr.c \
		my_putchar.c \
		my_put_nbr.c \
		func_default_ls.c \
		func_option_a.c \
		func_option_Amaj.c \
		func_option_d.c \
		func_option_l.c \
		func_option_rmin.c \
		func_display_list.c \
		func_init_list.c \
		func_insert_option.c \
		my_strcmp.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Werror -Wextra

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all	:	$(NAME)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all