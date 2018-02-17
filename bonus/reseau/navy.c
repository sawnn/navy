/*
** EPITECH PROJECT, 2018
** navy.c
** File description:
** a
*/

#include "my.h"

int	navy(int *csock)
{
	int player1 = 1;
	int player2 = 2;
	int letter;
	int nbr;
	int check;

	send(csock[0], &player1, sizeof(player1), 0);
	send(csock[1], &player2, sizeof(player2), 0);
	while (1) {
		recv(csock[0], &letter, sizeof(letter), 0);
		recv(csock[0], &nbr, sizeof(nbr), 0);
		send(csock[1], &letter, sizeof(letter), 0);
		send(csock[1], &nbr, sizeof(nbr), 0);
		recv(csock[1], &check, sizeof(check), 0);
		send(csock[0], &check, sizeof(check), 0);
		recv(csock[1], &letter, sizeof(letter), 0);
		recv(csock[1], &nbr, sizeof(nbr), 0);
		send(csock[0], &letter, sizeof(letter), 0);
		send(csock[0], &nbr, sizeof(nbr), 0);
		recv(csock[0], &check, sizeof(check), 0);
		send(csock[1], &check, sizeof(check), 0);
	}
	return (0);
}
