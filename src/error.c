/*
** EPITECH PROJECT, 2018
** error.c
** File description:
** a
*/

#include "my.h"

char	*c_p(char length, char fix, char notfix, char final)
{
	int i = -1;
	int j = -1;
	int o = -1;
	int p = 1;
	char *position = malloc(sizeof(char) * (((length - 48) * 2) + 1));

	if (position == NULL)
		return (NULL);
	p = notfix > final ? -1 : p;
	while (++i < (length - 48)) {
		if (fix < 49 || fix > 56) {
			position[++j] = fix;
			position[++j] = notfix;
			o = 1;
		}
		else if (fix >= 49 && fix <= 56) {
			position[++j] = notfix;
			position[++j] = fix;
			o = 2;
		}
		notfix = notfix + p;
	}
	position[++j] = '\0';
	if (position[j - o] != final)
		return (NULL);
	return (position);
}

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
		if (file[i][0] != ((++j) + 48))
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
	int i = -1;
	int j = -1;
	char **file = malloc(sizeof(char *) * (4 + sizeof(char*)));
	char **position;

	if (file == NULL)
		return (NULL);
	while ((file[++i] = get_next_line(fd)));
	if (i != 4)
		return (NULL);
	else if ((position = check_length(file)) == NULL)
		return (NULL);
	return (position);
}
