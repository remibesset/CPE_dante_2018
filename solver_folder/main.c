/*
** EPITECH PROJECT, 2019
** dante
** File description:
** main
*/

#include "solver.h"

void draw_map(char **map, lab_t *maze)
{
    for (int i = 0; i < maze->size_y; i++) {
        write(1, map[i], maze->size_x);
        write(1, "\n", 1);
    }
}

char **draw_way(lab_t *maze)
{
    int i = maze->mappint[0][0];

    maze->map[0][0] = 'o';
    while (i > 0) {
        maze->map = replace_number(i, maze);
        i--;
    }
    return (maze->map);
}

void solver(char *filepath, lab_t *maze)
{
    maze->map = load_map(maze->map, filepath, maze);
    maze->mappint = init_int(maze->mappint, maze);
    maze->mappint = set_obstacle(maze->mappint, maze->map, maze);
    maze->mappint = draw_ints(maze->map, maze->mappint, maze);
    maze->map = draw_way(maze);
    draw_map(maze->map, maze);
}

int main(int ac, char **av)
{
    lab_t maze;

    if (ac != 2)
        return (84);
    solver(av[1], &maze);
    return (0);
}
