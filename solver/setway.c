/*
** EPITECH PROJECT, 2019
** dante
** File description:
** setting the 'o'
*/

#include "solver.h"

int move_up(lab_t *maze, int i, int j)
{
    if (i > 0 && maze->mi[i - 1][j] == maze->number - 1) {
        maze->map[i - 1][j] = 'o';
        maze->number -= 1;
        return (1);
    }
    return (0);
}

int move_left(lab_t *maze, int i, int j)
{
    if (j > 0 && maze->mi[i][j - 1] == maze->number - 1) {
        maze->map[i][j - 1] = 'o';
        maze->number -= 1;
        return (1);
    }
    return (0);
}

int move_down(lab_t *maze, int i, int j)
{
    if (i < maze->size_y - 1 && maze->mi[i + 1][j] == maze->number - 1) {
        maze->map[i + 1][j] = 'o';
        maze->number -= 1;
        return (1);
    }
    return (0);
}

int move_right(lab_t *maze, int i, int j)
{
    if (j < maze->size_x - 1 && maze->mi[i][j + 1] == maze->number - 1) {
        maze->map[i][j + 1] = 'o';
        maze->number -= 1;
        return (1);
    }
    return (0);
}

void set_way(lab_t *maze, int i, int j)
{
    if (maze->map[i][j] == 'o') {
        if (move_up(maze, i, j) == 1)
            return;
        if (move_left(maze, i, j) == 1)
            return;
        if (move_right(maze, i, j) == 1)
            return;
        if (move_down(maze, i, j) == 1)
            return;
    }
}
