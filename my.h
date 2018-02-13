/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** a
*/

# ifndef MY_H
#  define MY_H
#  define READ_SIZE (100)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int my_getnbr(char *str);
void my_putchar(char c);
int navy(int fd);
char **check_file(int fd);
char **my_str_to_word_array(char *str);
char *get_next_line(int fd);
#endif
