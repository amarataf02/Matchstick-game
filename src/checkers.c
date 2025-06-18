/*
** EPITECH PROJECT, 2021
** check
** File description:
** line and matches
*/

#include "libmini.h"

int line_handle(char *g_lines, int lines, int *line)
{
    if (my_getnbr(g_lines) < 1 || my_getnbr(g_lines) > lines) {
        my_putstr("Error: this line is out of range\n");
        return (1);
    }
    if (line[my_getnbr(g_lines) - 1] == 0) {
        my_putstr("Error: not enough numbers on this line\n");
        return (1);
    }
    return (0);
}

int check_line(char **line_in, int *line, int lines)
{
    int len = 0;
    int i = 0;
    char *g_lines = my_malloc(35);
    size_t bufsize = 32;

    my_putstr("Line: ");
    len = getline(&g_lines, &bufsize, stdin);
    if (len == -1)
        return (84);
    while (g_lines[i] != '\0' && g_lines[i] != '\n') {
        if (g_lines[i] < '0' || g_lines[i] > '9') {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (1);
        }
        i++;
    }
    if (line_handle(g_lines, lines, line) == 1)
        return (1);
    *line_in = my_strdup(g_lines);
    return (0);
}

int match_handle(int max, char *match, int *line, int line_in)
{
    if (my_getnbr(match) <= 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (1);
    }
    if (my_getnbr(match) > max) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(max);
        my_putstr(" matches per turn\n");
        return (1);
    }
    if (my_getnbr(match) > line[line_in - 1]) {
        my_putstr("Error: not enough numbers on this line\n");
        return (1);
    }
    return (0);
}

int check_match(char **match_in, int max, int *line, int line_in)
{
    int len = 0;
    int i = 0;
    char *match = my_malloc(35);
    size_t bufsize = 32;

    my_putstr("Matches: ");
    len = getline(&match, &bufsize, stdin);
    if (len == -1)
        return (84);
    while (match[i] != '\n' && match[i] != '\0') {
        if (match[i] < '0' || match[i] > '9') {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (1);
        }
        i++;
    }
    if (match_handle(max, match, line, line_in) == 1)
        return (1);
    *match_in = my_strdup(match);
    return (0);
}