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

int     is_play(char **map, char **map_enemy, int x, int y);
void	print_game(char **map, char **map_enemy);
int	attack(int sock, char **map, char **map_enemy);
void	wait_attack(int sock, char **map, char **map_enemy, int one);
int	my_strlen(char *str);
char	*get_next_line(int fd);
void	print_map(char **map);
void	my_put_nbr(int nb);
void	my_putchar(char c);
int	player_two(char **file, int is_won, int sock);
int	player_one(char **file, int is_won, int sock);
int	navy(int *csock);
char	**check_file(int fd);
int my_getnbr(char *str);
char	**my_str_to_word_array(char *str);
char	**get_map(char **position);

#endif /* MY_H_ */
