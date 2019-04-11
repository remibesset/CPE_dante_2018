/*
** EPITECH PROJECT, 2019
** backtracking 2
** File description:
** check_mouv
*/

#include "generator.h"

int check_tab_mouv(char *tab)
{
    int i = 0;
    int pass = 0;

    for (i; i < 4; i++)
        if (tab[i] == '\0')
            pass++;
    if (pass == 4)
        return (1);
    return (0);
}