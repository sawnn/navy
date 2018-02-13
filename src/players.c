/*
** EPITECH PROJECT, 2018
** players.c
** File description:
** a
*/

#include "my.h"

int i = 0;

void	handler(int signum, siginfo_t *sig, void *context)
{
	signum = 0;
	context = NULL;
	i = sig->si_pid;
}

pid_t	get_pid()
{
	struct sigaction sa;
	pid_t pid;

	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	write(1, "my_pid: ", 8);
	my_put_nbr(getpid());
	write(1, "\nwaiting for enemy connection...\n", 33);
	while (i == 0)
		sigaction(SIGUSR1, &sa, NULL);
	pid = i;
	i = -1;
	write(1, "\nenemy connected\n\n", 18);
	return (pid);
}

int	player_one(int fd)
{
	char **file;
	char **map;
	char **map_enemy;
	pid_t pid;

	if ((file = check_file(fd)) == NULL)
		return (84);
	if ((map = get_map(file)) == NULL)
		return (84);
	if ((map_enemy = get_map(NULL)) == NULL)
		return (84);
	pid = get_pid();
	while (1) {
		print_game(map, map_enemy);
		attack(pid, map, map_enemy);
		write(1, "\nwaiting for enemy's attack...\n", 31);
		wait_attack(pid, map, map_enemy);
	}
}

void	connect_player(char *pid)
{
	usleep(10000);
	kill(my_getnbr(pid), SIGUSR1);
	write(1, "my_pid: ", 8);
	my_put_nbr(getpid());
	write(1, "\nsuccessfully connected\n\n", 25);
}

int	player_two(int fd, char *pid)
{
	char **file;
	char **map;
	char **map_enemy;

	if ((file = check_file(fd)) == NULL)
		return (84);
	if ((map = get_map(file)) == NULL)
		return (84);
	if ((map_enemy = get_map(NULL)) == NULL)
		return (84);
	connect_player(pid);
	while (1) {
		print_game(map, map_enemy);
		write(1, "waiting for enemy's attack...\n", 30);
		wait_attack(my_getnbr(pid), map, map_enemy);
		attack(my_getnbr(pid), map, map_enemy);
	}
}
