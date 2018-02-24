/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** c
*/

#include "my.h"


int	main(int ac, char **av)
{
	int fd;
	int i = 1;
	int check = -1;

	if (ac == 3)
		i = 2;
	if (ac == 1)
		return (84);
	fd = open(av[i], O_RDONLY);
	if (fd == -1)
		return (84);
	else if ((check = navy(fd, av, ac)) == 84)
		return (84);
	return (check);
}
