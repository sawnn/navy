/*
** EPITECH PROJECT, 2018
** players.c
** File description:
** a
*/

#include "my.h"

int	player_one(char **file, int is_won, int sock)
{
	char **map;
	char **map_enemy;

	if ((map = get_map(file)) == NULL)
		return (84);
	if ((map_enemy = get_map(NULL)) == NULL)
		return (84);
	while (is_won == 2) {
		print_game(map, map_enemy);
		if ((attack(sock, map, map_enemy)) == 84)
			return (84);
		is_won = is_play(map, map_enemy, -1, -1);
		is_won == 2 ? write(1, "\nwaiting for enemy's attack...\n", 31) : 0;
		is_won == 2 ? wait_attack(sock, map, map_enemy) : 0;
		is_won = is_won == 2 ? is_play(map, map_enemy, -1, -1) : is_won;
	}
	return (is_won);
}

int	player_two(char **file, int is_won, int sock)
{
	char **map;
	char **map_enemy;
	int check = 0;

	if ((map = get_map(file)) == NULL)
		return (84);
	if ((map_enemy = get_map(NULL)) == NULL)
		return (84);
	while (is_won == 2) {
		print_game(map, map_enemy);
		write(1, "\nwaiting for enemy's attack...\n", 31);
		wait_attack(sock, map, map_enemy);
		is_won = is_play(map, map_enemy, -1, -1);
		check = is_won == 2 ? attack(sock, map, map_enemy) : check;
		if (check == 84)
			return (84);
		is_won = is_won == 2 ? is_play(map, map_enemy, -1, -1) : is_won;
	}
	return (is_won);
}
