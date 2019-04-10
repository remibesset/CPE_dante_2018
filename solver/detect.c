/*
** EPITECH PROJECT, 2019
** dante
** File description:
** detect
*/

#include "solver.h"

int size_of_buffer(char *filepath)
{
    struct stat file;
    int size = 0;

    stat(filepath, &file);
    size = file.st_size;
    return (size);
}

int strline(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\n' && buffer[i] != '\0')
        i++;
    return (i);
}

int nb_of_line(char *buffer)
{
    int i = 0;
    int j = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            j++;
        i++;
    }
    return (j);
}

int is_next(lab_t *maze, int *pos, int number)
{
    if (pos[0] > 0 && maze->mappint[pos[0] - 1][pos[1]] == number - 1) {
        maze->map[pos[0] - 1][pos[1]] = 'o';
        return (1);
    } if (pos[1] > 0 && maze->mappint[pos[0]][pos[1] - 1] == number - 1) {
        maze->map[pos[0]][pos[1] - 1] = 'o';
        return (1);
    } if (pos[0] < maze->size_y - 1
    && maze->mappint[pos[0] + 1][pos[1]] == number - 1) {
        maze->map[pos[0] + 1][pos[1]] = 'o';
        return (1);
    } if (pos[1] < maze->size_x - 1
    && maze->mappint[pos[0]][pos[1] + 1] == number - 1) {
        maze->map[pos[0]][pos[1] + 1] = 'o';
        return (1);
    }
    return (0);
}
