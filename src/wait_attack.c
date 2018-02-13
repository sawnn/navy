/*
** EPITECH PROJECT, 2018
** wait_attack.c
** File description:
** a
*/

#include "my.h"

int	bin_to_dec(char *bin)
{
	int total = 0;
	int nb = 128;
	int o = 0;

	while (o < 8) {
		total = total + (nb * (bin[o] - 48));
		o++;
		nb /= 2;
	}
	return (total);
}

void	zero(int sig)
{
	if (sig == SIGUSR1) {
		i = 1;
	}
	else if (sig == SIGUSR2) {
		i = 0;
	}
}

int	get_signal(void)
{
	char *bin = malloc(sizeof(char) * 9);
	int j = 0;

	signal(SIGUSR2, zero);
	i = -1;
	while (j < 8) {
		signal(SIGUSR1, zero);
		signal(SIGUSR2, zero);
		if (i == 1) {
			bin[j++] = '1';
		}
		if (i == 0)
			bin[j++] = '0';
		i = -1;
	}
	bin[j] = '\0';
	return (bin_to_dec(bin));
}
