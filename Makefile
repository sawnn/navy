##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## a
##

SRC	=	src/get_next_line.c		\
		src/error.c			\
		src/navy.c			\
		src/my_putchar.c		\
		src/my_getnbr.c			\
		src/my_put_nbr.c		\
		src/players.c			\
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	./navy

all:	$(NAME)

CFLAGS	=	-g3 -I ./include

$(NAME):	 $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

