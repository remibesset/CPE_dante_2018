/*
** EPITECH PROJECT, 2019
** dante
** File description:
** algorith part
*/

#include "solver.h"

int **set_obstacle(int **mappint, char **map, lab_t *maze)
{
    for (int i = 0; i <= maze->size_y; i++)
        for (int j = 0; j <= maze->size_x; j++) {
            mappint[i][j] = (map[i][j] == 'X') ? -1 : 0;
        }
    mappint[maze->size_y][maze->size_x] = 1;
    return (mappint);
}

int **find_cond(int **mappint, int i, int j, lab_t *maze)
{
    printf("%d %d\n", i, j);
    if (mappint[i][j] == maze->number) {
        if (i > 0 && (mappint[i - 1][j] > mappint[i][j] + 1
            || mappint[i - 1][j] == 0))
            mappint[i - 1][j] = mappint[i][j] + 1;
        if (j > 0 && (mappint[i][j - 1] > mappint[i][j]
            || mappint[i][j - 1] == 0))
            mappint[i][j - 1] = mappint[i][j] + 1;
        if (j < maze->size_x - 1 && (mappint[i][j + 1] > mappint[i][j]
            || mappint[i][j + 1] == 0))
            mappint[i][j + 1] = mappint[i][j] + 1;
        if (i < maze->size_y - 1 && (mappint[i + 1][j] > mappint[i][j]
            || mappint[i + 1][j] == 0))
            mappint[i + 1][j] = mappint[i][j] + 1;
    }
    return (mappint);
}

int **find_and_set(int **mappint, char **map, lab_t *maze)
{
    int i;
    int j;

    for (i = maze->size_y; i >= 0; i--)
        for (j = maze->size_x; j >= 0; j--) {
            mappint = find_cond(mappint, i, j, maze);
        }
    maze->number++;
    return (mappint);
}

int **draw_ints(char **map, int **mappint, lab_t *maze)
{
    maze->number = 1;
    while (mappint[0][0] == 0)
        mappint = find_and_set(mappint, map, maze);
    return (mappint);
}

char **norme(lab_t *maze, int number, int i, int j)
{
    if (maze->mappint[i][j] == number && maze->map[i][j] == 'o')
        if (is_next(maze, (int[2]) {i, j}, number) == 1)
            return (maze->map);
}

char **replace_number(int number, lab_t *maze)
{
    for (int i = 0; i < maze->size_y; i++)
        for (int j = 0; j < maze->size_x; j++)
            norme(maze, number, i, j);
    return (maze->map);
}