/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** c
*/

#include "my.h"

int	*put_client(sockaddr_in sin, int sock, int sock_err)
{
	sockaddr_in csin;
	socklen_t taille = sizeof(csin);
	int i = 0;
	int *csock = malloc(sizeof(int) * 2);

	if ((sock_err = listen(sock, 5)) != -1) {
		write(1, "En attente de client\n", 21);
		while (i < 2) {
			csock[i] = accept(sock, (sockaddr*)&csin, &taille);
			i = csock[i] == -1 ? i : i + 1;
			i == 0 ? write(1, "raté\n", 5) : write(1, "ok\n", 3);
		}
	}
	else
		csock[i] = -1;
	return (csock);
}

int	reseau(int **csock)
{
	int sock;
	sockaddr_in sin;
	int sock_err;

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) != -1) {
		sin.sin_addr.s_addr = htonl(INADDR_ANY);
		sin.sin_family = AF_INET;
		sin.sin_port = htons(3001);
		if ((sock_err = bind(sock, (sockaddr*)&sin, sizeof(sin))) != -1)
			*csock = put_client(sin, sock, sock_err);
		else
			return (84);
		if (*csock[0] == -1)
			return (84);
	}
	else
		return (84);
	return (0);
}

int	main(int ac, char **av)
{
	int *csock;

	if (ac != 1)
		return (84);
	if ((reseau(&csock)) == 84)
		return (84);
	if (navy(csock) == 84)
		return (84);
	return (0);
}
