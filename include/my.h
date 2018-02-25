/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** michou
*/

#ifndef MY_H_
#define MY_H_
#define HELP if (put_position(x, y, position, map) == 84) return (NULL);
#define HELP2 HELP22 ? 'o' : 'x';
#define HELP22 (glob(-2) == 0 && map_enemy[str[1] - '1'][str[0] - 'A'] != 'x')
#define HELP3 map_enemy[y][x] == 'x' ? x_enemy + 1 : x_enemy;
#define HELP4 write(1, "\nwaiting for enemy's attack...\n", 31) : 0;
#define HELP5 attack(my_getnbr(pid), map, map_enemy) : check;
#define HELP6 r = (buff[0] == '\0' && r != NULL && r[0] == '\0') ? NULL : r;
#define READ_SIZE (100)

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	glob(int i);
int	is_play(char **map, char **map_enemy, int x, int y);
void	print_game(char **map, char **map_enemy);
int	attack(pid_t pid, char **map, char **map_enemy);
int	get_signal(void);
void	wait_attack(pid_t pid, char **map, char **map_enemy);
int	my_strlen(char *str);
char	*get_next_line(int fd);
void	print_map(char **map);
void	my_put_nbr(int nb);
void	my_putchar(char c);
int	player_two(char **file, char *pid, int is_won, int check);
int	player_one(char **file, int is_won, pid_t pid);
int	my_getnbr(char *str);
int	get_pos(char, char, int *, char *);
int	navy(int fd, char **av, int ac);
char	*c_p(char, char, char, char);
char	**check_file(int fd);
char	**my_str_to_word_array(char *str);
char	**get_map(char **position);

#endif /* MY_H_ */
