#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	dec_to_bin(int nb, pid_t pid)
{
	int i = 0;
	char c;
	int tmp = nb;

	while (i < 8) {
		nb <<= i;
		nb >>= 7;
		printf("%d\n", nb & 1);
		usleep(10000);
		if (nb & 1 == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);				
		nb = tmp;
		i++;
	}	
}

int main(int ac, char **av)
{
	pid_t pid;

	pid = getpid();
	printf("%d\n", pid);
	dec_to_bin(atoi(av[1]), atoi(av[2]));
}
