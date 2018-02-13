##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## a
##

SRC	=	get_next_line.c		\
		error.c			\
		navy.c			\
		my_putchar.c		\
		my_getnbr.c		\
		my_put_nbr.c		\
		players.c		\
		main.c					

OBJ	=	$(SRC:.c=.o)

NAME	=	./navy

all:	$(NAME)

CFLAGS	=	-g3

$(NAME):	 $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

