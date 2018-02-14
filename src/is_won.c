/*
** EPITECH PROJECT, 2018
** is_won.c
** File description:
** a
*/

#include "my.h"

int	is_play(char **map, char **map_enemy, int x, int y)
{
	int my_x = 0;
	int x_enemy = 0;

	while (map[++y])
		if (map[y][++x] == 'x')
			my_x++;
	y = -1;
	x = -1;
	while (map_enemy[++y])
		if (map_enemy[y][++x] == 'x')
			x_enemy++;
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
