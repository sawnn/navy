/*
** EPITECH PROJECT, 2018
** navy.c
** File description:
** a
*/

#include "my.h"

int	put_position(int x, int y, char **position, char **map)
{
	static int j = 0;
	static int i = 0;

	if ((x + 1) % 2 == 1)
		j = position[y][x] - 65;
	else {
		i = position[y][x] - 49;
		if (map[i][j] != '.')
			return (84);
		map[i][j] = y + 50;
	}
	return (0);
}

char	**get_map(char **position)
{
	int i = -1;
	int j = -1;
	int x = -1;
	int y = -1;
	char **map = malloc(sizeof(char *) * 8 + sizeof(char *));

	while (++i < 8) {
		map[i] = malloc(sizeof(char) * 9);
		while (++j < 8)
			map[i][j] = '.';
		map[i][j] = '\0';
		j = -1;
	}
	map[i] = NULL;
	while (position[++y]) {
		while (position[y][++x])
			if (put_position(x, y, position, map) == 84)
				return (NULL);
		x = -1;
	}
	return (map);
}

void	print_map(char **map)
{
	int i = -1;
	int j = -1;

	write(1, " |A B C D E F G H\n-+---------------\n", 37);
	while (map[++i]) {
		my_putchar(i + 49);
		write(1, "|", 1);
		while (map[i][++j]) {
			my_putchar(map[i][j]);
			write(1, " ", 1);
		}
		write(1, "\n", 1);
		j = -1;
	}
}

int	navy(int fd, char **av, int ac)
{
	if (ac == 2)
		player_one(fd);
	else
		player_two(fd, av[1]);
	//print_map(map);
	return (0);

}
