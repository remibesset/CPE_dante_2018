/*
** EPITECH PROJECT, 2019
** dante
** File description:
** algorith part
*/

#include "solver.h"

void set_next(lab_t *maze, int i, int j)
{
    if (maze->mi[i][j] == maze->number) {
        maze->nb += 1;
        if (i > 0 && maze->mi[i - 1][j] != -1 &&
        (maze->mi[i - 1][j] > maze->number + 1 || maze->mi[i - 1][j] == 0)) {
            maze->mi[i - 1][j] = maze->number + 1;
            maze->actnb++;
        } if (i < maze->size_y - 1 && maze->mi[i + 1][j] != -1 &&
        (maze->mi[i + 1][j] > maze->number + 1 || maze->mi[i + 1][j] == 0)) {
            maze->mi[i + 1][j] = maze->number + 1;
            maze->actnb++;
        } if (j > 0 && maze->mi[i][j - 1] != -1 &&
        (maze->mi[i][j - 1] > maze->number + 1 || maze->mi[i][j - 1] == 0)) {
            maze->mi[i][j - 1] = maze->number + 1;
            maze->actnb++;
        } if (j < maze->size_x - 1 && maze->mi[i][j + 1] != -1 &&
        (maze->mi[i][j + 1] > maze->number + 1 || maze->mi[i][j + 1] == 0)) {
            maze->mi[i][j + 1] = maze->number + 1;
            maze->actnb++;
        }
    }
}

void set_moves(lab_t *maze)
{
    maze->ite = nb_of_number(maze);
    maze->nb = 0;
    for (int i = 0; maze->nb < maze->ite && i < maze->size_y; i++)
        for (int j = 0; maze->nb < maze->ite && j < maze->size_x; j++)
            set_next(maze, i, j);
    if (maze->actnb > 0) {
        maze->number += 1;
        maze->actnb = 0;
    }
}

void draw_moves(lab_t *maze)
{
    maze->number = 1;
    maze->verif = 1;
    while (maze->mi[maze->size_y - 1][maze->size_x - 1] == 0) {
        if (maze->number > 7000)
            error_impossible();
        maze->verif = maze->number;
        set_moves(maze);
        if (maze->verif == maze->number) {
            error_impossible();
        }
    }
}