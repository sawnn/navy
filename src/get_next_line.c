/*
** EPITECH PROJECT, 2017
** get_next_line.c
** File description:
** a
*/

#include "my.h"

int	check(char *buff)
{
	static int i = -1;
	int j = 0;
	char *tmp = buff;

	i++;
	if (i != 0) {
		while (tmp[i] != '\0')
			buff[j++] = tmp[i++];
		buff[j] = '\0';
		i = 0;
	}
	while (buff[i] != '\0') {
		if (buff[i] == '\n') {
			return (i);
		}
		i++;
	}
	i = -1;
	return (-1);
}

int	my_strlen(char *str)
{
	int i = -1;

	while (str[++i] != '\0');
	return (i);
}

char	*my_strncat(char *dest, char *src, int nb)
{
	int i = 0;
	int t1 = -1;

	while (dest[++t1] != '\0');
	while (i < nb && src[i]) {
		dest[t1 + i] = src[i];
		i++;
	}
	dest[t1 + i] = '\0';
	return (dest);
}

char	*add_line(char *buff, int i, char *rest)
{
	char *tmp;

	if (rest == NULL) {
		if ((tmp = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
			return (NULL);
		tmp[0] = '\0';
		my_strncat(tmp, buff, i);
	}
	else {
		if ((tmp = malloc(sizeof(char) * READ_SIZE
				  + my_strlen(rest) + 1)) == NULL)
			return (NULL);
		tmp[0] = '\0';
		my_strncat(tmp, rest, my_strlen(rest));
		my_strncat(tmp, buff, i);
	}
	free(rest);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char buff[READ_SIZE];
	int ret;
	static int i = -1;
	char *r = NULL;

	while (fd >= 0) {
		if (i == -1) {
			buff[(ret = read(fd, buff, READ_SIZE))] = '\0';
			HELP6
		}
		if ((ret == 0 && i == -1 && r == NULL) || ret == -1)
			return (NULL);
		else if ((ret == 0 && i == -1 && r != NULL) || ret == -1)
			return (r);
		r = (i = check(buff)) == -1 ? add_line(buff, READ_SIZE, r) : r;
		if (i == -1 && r == NULL)
			return (NULL);
		if (i != -1)
			return ((add_line(buff, i, r)));
	}
	return (NULL);
}
