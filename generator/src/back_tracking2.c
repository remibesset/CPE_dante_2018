/*
** EPITECH PROJECT, 2019
** backtracking 2
** File description:
** check_mouv
*/

#include "generator.h"

int check_tab_mouv(int *tab)
{
    int i = 0;
    int pass = 0;

    for (i; i < 4; i++)
        if (tab[i] == 0)
            pass++;
    if (pass == 4)
        return (1);
    return (0);
}

void switch_direction(int j, gen_t *gen)
{
    switch (j) {
    case UP:
        make_path(gen, 0, -2);
        break;
    case DOWN:
        make_path(gen, 0, 2);
        break;
    case RIGHT:
        make_path(gen, 2, 0);
        break;
    case LEFT:
        make_path(gen, -2, 0);
        break;
    default:
        break;
    }
}