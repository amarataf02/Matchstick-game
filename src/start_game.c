/*
** EPITECH PROJECT, 2021
** start
** File description:
** start game
*/

#include "libmini.h"

int ai_win(int *line, int lines)
{
    int i = 0;

    while (i < lines) {
        if (line[i] != 0)
            return (0);
        i++;
    }
    my_putstr("You lost, too bad\n");
    return (1);
}

int p_win(int *line, int lines)
{
    int i = 0;

    while (i < lines) {
        if (line[i] != 0)
            return (0);
        i++;
    }
    my_putstr("I lost... snif... but I'll get you next time!!\n");
    return (1);
}

int loop(int *line, int lines, int cols, int max)
{
    char *line_in = my_malloc(35);
    char *match_in = my_malloc(35);

    while (1) {
        print_map(line, lines, cols);
        if (p_win(line, lines) == 1)
            return (1);
        my_putstr("\nYour turn:\n");
        if (get_of_line(&line_in, line, lines) == 1)
            return (0);
        if (get_of_match(&match_in, max, line, line_in) == 1)
            return (0);
        line = print_inp(my_getnbr(line_in), my_getnbr(match_in), line);
        print_map(line, lines, cols);
        if (ai_win(line, lines) == 1)
            return (2);
        line = calc_ai(line, max, lines);
    }
    return (0);
}

int start_game(int lines, int max)
{
    int *line = malloc(sizeof(int) * lines + 2);
    int i = 0;
    int y = 1;
    int cols = 0;

    if (line == NULL)
        return (84);
    line[lines] = -2;
    while (i < lines) {
        line[i] = y;
        y = y + 2;
        i++;
    }
    cols = line[lines - 1];
    i = loop(line, lines, cols, max);
    return (i);
}