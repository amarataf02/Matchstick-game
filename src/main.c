/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/

#include "libmini.h"

int error_handle(int ac, char **av)
{
    int i = 0;
    int y = 0;

    if (ac != 3)
        return (84);
    while (i < my_strlen(av[1])) {
        if (av[1][i] < 48 || av[1][i] > 57)
            return (84);
        i++;
    }
    while (y < my_strlen(av[2])) {
        if (av[2][y] < 48 || av[2][y] > 57)
            return (84);
        y++;
    }
    if (my_getnbr(av[1]) < 2 || my_getnbr(av[1]) > 99)
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    int i = 0;
    if (error_handle(ac, av) == 84)
        return (84);
    if (my_getnbr(av[2]) < 1 || my_getnbr(av[2]) > 2147483647
    || my_strlen(av[2]) > 10)
        return (84);
    i = start_game(my_getnbr(av[1]), my_getnbr(av[2]));
    return (i);
}