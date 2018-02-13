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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

extern int i;

void	print_game(char **map, char **map_enemy);
int	attack(pid_t pid, char **map, char **map_enemy);
int	get_signal(void);
int	wait_attack(pid_t pid, char **map, char **map_enemy);
int	my_strlen(char *str);
char	*get_next_line(int fd);
void	print_map(char **map);
void	my_put_nbr(int nb);
void	my_putchar(char c);
int	player_two(int fd, char *pid);
int	player_one(int fd);
int	my_getnbr(char *str);
int	navy(int fd, char **av, int ac);
char	**check_file(int fd);
char	**my_str_to_word_array(char *str);
char	**get_map(char **position);

#endif /* MY_H_ */
