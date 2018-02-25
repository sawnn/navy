/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** a
*/

#include "my.h"

int	nb_digit(int nb)
{
	int increment = 10;
	int results = 0;

	while (results != nb) {
		results = nb % increment;
		increment = increment * 10;
	}
	return (increment / 100);
}

void	my_put_nbr(int nb)
{
	int putch = 0;
	int nb_of_digit = nb_digit(nb);

	if (nb < 0)
		nb = nb * -1;
	while (nb_of_digit > 0) {
		putch = nb / nb_of_digit % 10;
		nb_of_digit = nb_of_digit / 10;
		my_putchar(putch + 48);
	}
}
