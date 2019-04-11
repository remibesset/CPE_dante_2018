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

char **malloc_tab(char **tab, char *buffer, lab_t *maze)
{
    int k = 0;

    maze->size_x = strline(buffer) - 1;
    maze->size_y = nb_of_line(buffer);
    tab = malloc(sizeof(char *) * (maze->size_y + 1));
    for (int i = 0; i <= maze->size_y; i++) {
        tab[i] = malloc(sizeof(char) * (maze->size_x + 1));
        for (int j = 0; j < strline(buffer); j++) {
            tab[i][j] = buffer[k];
            k++;
        }
        k++;
    }
    return (tab);
}

char **load_map(char **map, char *filepath, lab_t *maze)
{
    int size = size_of_buffer(filepath);
    char *buffer = file_to_buffer(filepath, size);
    char **tab = malloc_tab(tab, buffer, maze);

    return (tab);
}

int **init_int(int **mappint, lab_t *maze)
{
    mappint = malloc(sizeof(int *) * maze->size_y + 1);

    for (int i = 0; i <= maze->size_y; i++) {
        mappint[i] = malloc(sizeof(int) * (maze->size_x + 1));
    }
    for (int i = 0; i <= maze->size_y; i++) {
        for (int j = 0; j <= maze->size_x; j++) {
            mappint[i][j] = 0;
        }
    }
    return (mappint);
}
