/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** c
*/

#include "my.h"


int main(int ac, char **av)
{
	int fd;
	
	if (ac == 1)
		return (84);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (84);
	else if (navy(fd) == 84)
		return (84);
	return (0);
}
