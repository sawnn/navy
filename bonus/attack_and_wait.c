/*
** EPITECH PROJECT, 2018
** attack_and_wait.c
** File description:
** a
*/

#include "my.h"

int	error_position(char *str)
{
	if (!str)
		return (84);
	if (my_strlen(str) != 2)
		return (84);
	return (str[0] < 'A' || str[0] > 'H' || str[1] < '1' || str[1] > '8');
}

int	atk(int x, char **map_enemy, char *str)
{
	if (x == 0) {
		write(1, ": missed\n", 9);
		if (map_enemy[str[1] - '1'][str[0] - 'A'] != 'x')
			map_enemy[str[1] - '1'][str[0] - 'A'] = 'o';
	}
	else if (x == 1) {
		write(1, ": hit\n", 6);
		map_enemy[str[1] - '1'][str[0] - 'A'] = 'x';
	}
	return (0);
}

int	attack(int sock, char **map, char **map_enemy)
{
	char *str;
	int x;
	int j;

	write(1, "\nattack: ", 9);
	while (error_position((str = get_next_line(0)))) {
		if (str == NULL)
			return (84);
		write(1, "wrong position\n", 15);
		write(1, "\nattack: ", 9);
	}
	x = str[0] - 'A';
	j = str[1] - '1';
	send(sock, &j, sizeof(j), 0);
	send(sock, &x, sizeof(x), 0);
	write(1, str, 2);
	recv(sock, &x, sizeof(x), 0);
	return (atk(x, map_enemy, str));
}

void	wait_attack(int sock, char **map, char **map_enemy)
{
	int i;
	int j;
	int one = 1;
	int zero = 0;

	recv(sock, &j, sizeof(j), 0);
	recv(sock, &i, sizeof(i), 0);
	if (map[j][i] == '.' || map[j][i] == 'x' || map[j][i] == 'o') {
		my_putchar(i + 'A');
		my_putchar(j + '1');
		write(1, ": missed\n", 9);
		if (map[j][i] != 'x')
			map[j][i] = 'o';
		send(sock, &zero, 4, 0);
	}
	else {
		my_putchar(i + 'A');
		my_putchar(j + '1');
		write(1, ": hit\n", 6);
		map[j][i] = 'x';
		send(sock, &one, 4, 0); 
	}
}
