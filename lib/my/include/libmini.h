/*
** EPITECH PROJECT, 2020
** my
** File description:
** header file
*/

#ifndef MINI_H_
#define MINI_H_

#include "libmy.h"
#include <stdio.h>

void print_map(int *line, int lines, int cols);
int start_game(int lines, int max);
int *print_inp(int line_in, int matches, int *line);
int *calc_ai(int *line, int max, int lines);
int check_line(char **line_in, int *line, int lines);
int check_match(char **match_in, int max, int *line, int line_in);
int get_of_line(char **line_in, int *line, int lines);
int get_of_match(char **match_in, int max, int *line, char *line_in);

#endif