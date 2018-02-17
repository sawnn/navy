##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## a
##

SRC	=	navy.c				\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	./reseau

all:	$(NAME)

CFLAGS	=	-I ./include

$(NAME):	 $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

