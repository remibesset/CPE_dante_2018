/*
** EPITECH PROJECT, 2019
** dante
** File description:
** main
*/

#include "solver.h"

void error_impossible(void)
{
    printf("no solution found");
    exit(0);
}

void set_map(lab_t *maze)
{
    for (int i = maze->size_y - 1; i >= 0; i--)
        for (int j = maze->size_x - 1; j >= 0; j--)
            set_way(maze, i, j);
}

int solver(char *filepath, lab_t *maze)
{
    load_map(filepath, maze);
    init_int(maze);
    draw_moves(maze);
    while (maze->map[0][0] != 'o')
        set_map(maze);
    for (int i = 0; i < maze->size_y; i++) {
        if (i != 0)
            printf("\n");
        printf(maze->map[i]);
    }
    return (0);
}

int main(int ac, char **av)
{
    lab_t maze;

    if (ac != 2)
        return (84);
    return (solver(av[1], &maze));
}
