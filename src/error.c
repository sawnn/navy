/*
** EPITECH PROJECT, 2018
** error.c
** File description:
** a
*/

#include "my.h"

int	get_pos(char fix, char notfix, int *j, char *position)
{
	*j = *j + 1;
	if (fix < 49 || fix > 56) {
		position[*j] = fix;
		*j = *j + 1;
		position[*j] = notfix;
		return (1);
	}
	else if (fix >= 49 && fix <= 56) {
		position[*j] = notfix;
		*j = *j + 1;
		position[*j] = fix;
		return (2);
	}
}

char	*c_p(char length, char fix, char notfix, char final)
{
	int i = -1;
	int j = -1;
	int o = -1;
	int p = notfix > final ? -1 : 1;
	char *position = malloc(sizeof(char) * (((length - 48) * 2) + 1));

	if (position == NULL)
		return (NULL);
	while (++i < (length - 48)) {
		o = get_pos(fix, notfix, &j, position);
		notfix = notfix + p;
	}
	position[++j] = '\0';
	if (position[j - o] != final)
		return (NULL);
	return (position);
}

