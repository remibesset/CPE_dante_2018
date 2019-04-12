/*
** EPITECH PROJECT, 2019
** dante
** File description:
** init stat
*/

#include "solver.h"

char *load_file_in_mem(char const *filepath, char *buffer, int size)
{
    int fd = 0;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        exit(84);
    read(fd, buffer, size);
    close(fd);
    return (buffer);
}

char *file_to_buffer(char *filepath, int size)
{
    char *buffer = malloc(sizeof(char) * size + 2);

    for (int i = 0; i < size + 1; i++)
        buffer[i] = '\0';
    buffer = load_file_in_mem(filepath, buffer, size);
    return (buffer);
}

void malloc_tab(lab_t *maze)
{
    int k = 0;

    maze->size_x = strline(maze->buffer);
    maze->size_y = nb_of_line(maze->buffer);
    maze->map = malloc(sizeof(char *) * maze->size_y);
    for (int i = 0; i < maze->size_y; i++) {
        maze->map[i] = malloc(sizeof(char) * (maze->size_x + 1));
        maze->map[i][maze->size_x] = '\0';
        for (int j = 0; j < maze->size_x; j++) {
            maze->map[i][j] = maze->buffer[k];
            k++;
        }
        k++;
    }
}

void load_map(char *filepath, lab_t *maze)
{
    int size = size_of_buffer(filepath);
    maze->buffer = file_to_buffer(filepath, size);
    malloc_tab(maze);
    maze->map[maze->size_y - 1][maze->size_x - 1] = 'o';
}

void init_int(lab_t *maze)
{
    maze->mi = malloc(sizeof(int *) * maze->size_y);

    for (int i = 0; i < maze->size_y; i++) {
        maze->mi[i] = malloc(sizeof(int) * maze->size_x + 1);
    }
    for (int i = 0; i < maze->size_y; i++) {
        for (int j = 0; j < maze->size_x; j++) {
            maze->mi[i][j] = (maze->map[i][j] == 'X') ? -1 : 0;
        }
    }
    maze->mi[0][0] = 1;
    maze->actnb = 0;
}
