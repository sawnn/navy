/*
** EPITECH PROJECT, 2018
** attack_and_wait.c
** File description:
** a
*/

#include "my.h"

int	error_position(char *str)
{
	if (!str)
		return (84);
	if (my_strlen(str) != 2)
		return (84);
	return (str[0] < 'A' || str[0] > 'H' || str[1] < '1' || str[1] > '8');
}

void	dec_to_bin(int nb, pid_t pid)
{
	int o = -1;
	int tmp = nb;

	while (++o < 8) {
		nb <<= o;
		nb >>= 7;
		usleep(10000);
		if (nb & 1 == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		nb = tmp;
	}
}

void	atk(int sig)
{
	if (sig == SIGUSR1) {
		i = 0;
		write(1, ": missed\n", 9);
	}
	else if (sig == SIGUSR2) {
		write(1, ": hit\n", 6);
		i = 1;
	}
}

int	attack(pid_t pid, char **map, char **map_enemy)
{
	char *str;

	write(1, "\nattack: ", 9);
	while (error_position((str = get_next_line(0)))) {
		write(1, "wrong position\n", 15);
		write(1, "\nattack: ", 9);
	}
	dec_to_bin(str[0] - 'A', pid);
	dec_to_bin(str[1] - '1', pid);
	write(1, str, 2);
	i = -1;
	while (i == -1) {
		signal(SIGUSR1, atk);
		signal(SIGUSR2, atk);
	}
	if (i == 0)
		map_enemy[str[1] - '1'][str[0] - 'A'] = 'o';
	else
		map_enemy[str[1] - '1'][str[0] - 'A'] = 'x';
	i = -1;
}

int	wait_attack(pid_t pid, char **map, char **map_enemy)
{
	int i = get_signal();
	int j = get_signal();

	if (map[j][i] == '.') {
		my_putchar(i + 'A');
		my_putchar(j + '1');
		write(1, ": missed\n", 9);
		map[j][i] = 'o';
		usleep(10000);
		kill(pid, SIGUSR1);
	}
	else {
		my_putchar(i + 'A');
		my_putchar(j + '1');
		write(1, ": hit\n", 6);
		map[j][i] = 'x';
		usleep(10000);
		kill(pid, SIGUSR2);
	}
}
