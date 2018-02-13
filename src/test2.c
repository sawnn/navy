#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int i = -1;

void	bin_to_dec(char *bin)
{
	int total = 0;
	int nb = 128;
	int i = 0;

	while (i < 8) {
		total = total + (nb * (bin[i] - 48));
		i++;
		nb /= 2;
	}
	printf("%d\n", total);
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

int main(int ac, char **av)
{
	int pid = getpid();
	char *bin = malloc(sizeof(char) * 9);
	int j = 0;
	
	printf("%d\n", pid);
	while (j < 8) {
		signal(SIGUSR2, zero);
		signal(SIGUSR1, zero);
		if (i == 1) {
			bin[j++] = '1';
		}
		if (i == 0)
			bin[j++] = '0';
		i = -1;
	}
	bin[j] = '\0';
	printf("%s\n", bin);
	bin_to_dec(bin);
}
