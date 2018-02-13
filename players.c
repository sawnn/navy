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
int	player_one(int fd)
{
	struct sigaction sa;
	pid_t pid;
	char **file;
	char **map;

	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	if ((file = check_file(fd)) == NULL)
		return (84);
	if ((map = get_map(file)) == NULL)
		return (84);
	write(1, "my_pid: ", 8);
	my_put_nbr(getpid());
	write(1, "\nwaiting for enemy connection...\n", 33);
	while (i == 0)
		sigaction(SIGUSR1, &sa, NULL);
	pid = i;
	write(1, "\nenemy connected\n", 17);
}

int	player_two(int fd, char *pid)
{
	char **file;
	char **map;

        if ((file = check_file(fd)) == NULL)
                return (84);
        if ((map = get_map(file)) == NULL)
                return (84);
	usleep(10000);
	kill(my_getnbr(pid), SIGUSR1);
	write(1, "my_pid: ", 8);
        my_put_nbr(getpid());
	write(1, "\nsuccessfully connected\n", 24); 
}
