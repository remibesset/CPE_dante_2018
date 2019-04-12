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
    j++;
    return (j);
}

int nb_of_number(lab_t *maze)
{
    int nb = 0;

    for (int i = 0; i < maze->size_y; i++)
        for (int j = 0; j < maze->size_x; j++)
            nb = (maze->mi[i][j] == maze->number)
            ? nb + 1 : nb;
    return (nb);
}