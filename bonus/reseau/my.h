/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** michou
*/

#ifndef MY_H_
#define MY_H_

#define READ_SIZE (100)

#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
typedef struct sockaddr_in sockaddr_in;
typedef struct sockaddr sockaddr;

int	navy(int *csock);


#endif /* MY_H_ */
