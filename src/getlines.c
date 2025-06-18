/*
** EPITECH PROJECT, 2021
** getlines
** File description:
** getter
*/

#include "libmini.h"

int get_of_line(char **line_in, int *line, int lines)
{
    int i = 1;

    while (i != 0) {
        i = check_line(line_in, line, lines);
        if (i == 84)
            return (1);
    }
    return (0);
}

int get_of_match(char **match_in, int max, int *line, char *line_in)
{
    int i = 2;
    int x = 1;
    int lines = 0;

    while (line[lines] >= 0)
        lines++;
    while (i != 0) {
        if (i != 2) {
            x = get_of_line(&line_in, line, lines);
            i = check_match(match_in, max, line, my_getnbr(line_in));
        }
        if (i == 2)
            i = check_match(match_in, max, line, my_getnbr(line_in));
        if (i == 84 || x == 84)
            return (1);
    }
    return (0);
}