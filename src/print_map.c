/*
** EPITECH PROJECT, 2021
** print
** File description:
** print_map
*/

#include "libmini.h"

void print_tops(int cols)
{
    int i = 0;

    while (i <= cols + 1) {
        my_putstr("*");
        i++;
    }
    my_putstr("\n");
}

char *create_str(int cols, int i, int lines, int *line)
{
    int y = 0;
    int x = 0;
    char *star = malloc(sizeof(char) * cols + 2);

    while (y < (lines - i - 1)) {
        star[y] = ' ';
        y++;
    }
    while (x < line[i]) {
        star[y] = '|';
        y++;
        x++;
    }
    while (y < cols) {
        star[y] = ' ';
        y++;
    }
    return (star);
}

char **create_map(char **star, int lines, int cols, int *line)
{
    int i = 0;

    while (i < lines) {
        star[i] = create_str(cols, i, lines, line);
        i++;
    }
    return (star);
}

void print_map(int *line, int lines, int cols)
{
    char **star = malloc(sizeof(char *) * lines + 2);
    int x = 0;

    star = create_map(star, lines, cols, line);
    print_tops(cols);
    while (x <= lines - 1) {
        my_putchar('*');
        my_putstr(star[x]);
        my_putchar('*');
        my_putchar('\n');
        x++;
    }
    print_tops(cols);
}