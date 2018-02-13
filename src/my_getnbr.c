/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** a
*/

#include "my.h"

int	my_getnbr(char *str)
{
	int i = 0;
	int j = 0;

	if (str == NULL)
		return (-2);
	else if (str[0] == '-')
		i++;
	while (str[i]) {
		if ((str[i] < '0' || str[i] > '9'))
			return (-1);
		j = j + str[i++] - 48;
		j = j * 10;
	}
	if (str[0] == '\0')
		return (-1);
	j = j / 10;
	if (str[0] == '-')
		return (-1);
	else
		return (j);
}
