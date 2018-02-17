##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## a
##

SRC	=	error.c			\
		my_putchar.c			\
		my_getnbr.c			\
		my_put_nbr.c			\
		players.c			\
		get_next_line.c		\
		attack_and_wait.c		\
		is_won.c			\
		client.c

OBJ	=	$(SRC:.c=.o)

NAME	=	./navy

all:	$(NAME)

CFLAGS	=	-I ./include

$(NAME):	 $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

