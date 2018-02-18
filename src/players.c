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

pid_t	get_pid(void)
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
	write(1, "\nenemy connected\n", 17);
	return (pid);
}

int	player_one(char **file, int is_won, pid_t pid)
{
	char **map;
	char **map_enemy;

	if ((map = get_map(file)) == NULL)
		return (84);
	if ((map_enemy = get_map(NULL)) == NULL)
		return (84);
	pid = get_pid();
	while (is_won == 2) {
		print_game(map, map_enemy);
		if ((attack(pid, map, map_enemy)) == 84)
			return (84);
		is_won = is_play(map, map_enemy, -1, -1);
		is_won == 2 ? write(1, "\nwaiting for enemy's attack...\n", 31) : 0;
		is_won == 2 ? wait_attack(pid, map, map_enemy) : 0;
		is_won = is_won == 2 ? is_play(map, map_enemy, -1, -1) : is_won;
	}
	return (is_won);
}

int	connect_player(char *pid)
{
	usleep(10000);
	if (kill(my_getnbr(pid), SIGUSR1) == -1)
		return (84);
	write(1, "my_pid: ", 8);
	my_put_nbr(getpid());
	write(1, "\nsuccessfully connected\n", 24);
}

int	player_two(char **file, char *pid, int is_won, int check)
{
	char **map;
	char **map_enemy;

	if ((map = get_map(file)) == NULL)
		return (84);
	if ((map_enemy = get_map(NULL)) == NULL)
		return (84);
	if (connect_player(pid) == 84)
		return (84);
	while (is_won == 2) {
		print_game(map, map_enemy);
		write(1, "\nwaiting for enemy's attack...\n", 31);
		wait_attack(my_getnbr(pid), map, map_enemy);
		is_won = is_play(map, map_enemy, -1, -1);
		check = is_won == 2 ? attack(my_getnbr(pid), map, map_enemy) : check;
		if (check == 84)
			return (84);
		is_won = is_won == 2 ? is_play(map, map_enemy, -1, -1) : is_won;
	}
	return (is_won);
}
