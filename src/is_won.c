/*
** EPITECH PROJECT, 2018
** is_won.c
** File description:
** a
*/

#include "my.h"

int	who_won(int my_x, int x_enemy)
{
	if (my_x == 14) {
		write(1, "\nEnemy won\n", 11);
		return (1);
	}
	else if (x_enemy == 14) {
		write(1, "\nI won\n", 7);
		return (0);
	}
	return (2);
}

int	is_play(char **map, char **map_enemy, int x, int y)
{
	int my_x = 0;
	int x_enemy = 0;

	while (map[++y]) {
		while (map[y][++x])
			my_x = map[y][x] == 'x' ? my_x + 1 : my_x;
		x = -1;
	}
	y = -1;
	x = -1;
	while (map_enemy[++y]) {
		while (map_enemy[y][++x])
			x_enemy = map_enemy[y][x] == 'x' ? x_enemy + 1 : x_enemy;
		x = -1;
	}
	return (who_won(my_x, x_enemy));
}
