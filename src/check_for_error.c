/*
** EPITECH PROJECT, 2018
** check_for_error.c
** File description:
** a
*/

#include "my.h"

int	check_chara(char **f, int i)
{
	if (f[i][2] < 65 || f[i][2] > 72 || f[i][3] < 49 || f[i][3] > 56)
		return (84);
	if (f[i][5] < 65 || f[i][5] > 72 || f[i][6] < 49 || f[i][6] > 56)
		return (84);
	return (0);
}

char	**check_place(char **f)
{
	int j = -1;
	int i = -1;
	char **position = malloc(sizeof(char *) * 5);

	if (position == NULL)
		return (NULL);
	while (f[++i]) {
		if (check_chara(f, i) == 84)
			return (NULL);
		if (f[i][2] == f[i][5])
			position[++j] = c_p(f[i][0], f[i][2], f[i][3], f[i][6]);
		else
			position[++j] = c_p(f[i][0], f[i][3], f[i][2], f[i][5]);
		if (position[j] == NULL)
			return (NULL);
	}
	position[++j] = NULL;
	return (position);
}

char	**check_length(char **file)
{
	int i = -1;
	int j = 1;
	char **position;

	while (file[++i])
		if (file[i][0] < '2' || file[i][0] > '5')
			return (NULL);
	i = -1;
	while (file[++i])
		if (file[i][1] != ':' || file[i][4] != ':')
			return (NULL);
	if ((position = check_place(file)) == NULL)
		return (NULL);
	return (position);
}

char	**check_file(int fd)
{
	int i = 0;
	int j = -1;
	char **file = malloc(sizeof(char *) * (4 + sizeof(char*)));
	char **position;

	if (file == NULL)
		return (NULL);
	while ((file[i] = get_next_line(fd)))
		i = file[i][0] != '\0' ? i + 1 : i;
	if (i != 4)
		return (NULL);
	if ((position = check_length(file)) == NULL)
		return (NULL);
	return (position);
}
