##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## a
##

SRC	=	src/error.c			\
		src/navy.c			\
		src/my_putchar.c		\
		src/my_getnbr.c			\
		src/my_put_nbr.c		\
		src/players.c			\
		src/get_next_line.c		\
		src/attack_and_wait.c		\
		src/wait_attack.c		\
		src/is_won.c			\
		src/main.c

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

