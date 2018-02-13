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

void my_put_nbr(int nb);
void my_putchar(char c);
int player_two(int fd, char *pid);
int player_one(int fd);
int my_getnbr(char *str);
int navy(int fd, char **av, int ac);
char *get_next_line(int fd);
char **check_file(int fd);
char **my_str_to_word_array(char *str);
char **get_map(char **position);

#endif /* MY_H_ */
