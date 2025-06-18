/*
** EPITECH PROJECT, 2021
** cal
** File description:
** ai
*/

#include "libmini.h"

int *print_inp(int line_in, int matches, int *line)
{
    my_putstr("Player removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line_in);
    my_putstr("\n");
    line[line_in - 1] = line[line_in - 1] - matches;
    return (line);
}

int *calc_ai(int *line, int max, int lines)
{
    int ai_l = 0;
    int ai_m = 0;
    int i = 0;

    my_putstr("\nAI's turn...\n");
    while (i < lines) {
        if (line[i] > 0) {
            ai_l = i + 1;
            ai_m = 1;
            line[i] = line[i] - 1;
            i = lines;
        }
        i++;
    }
    my_putstr("AI removed ");
    my_put_nbr(ai_m);
    my_putstr(" match(es) from line ");
    my_put_nbr(ai_l);
    my_putchar('\n');
    return (line);
}