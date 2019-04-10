/*
** EPITECH PROJECT, 2019
** dante
** File description:
** solver header
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifndef SOLVER_H_
#define SOLVER_H_

typedef struct lab_s
{
    char **map;
    int size_x;
    int size_y;
    int **mappint;
    int number;
} lab_t;

char *load_file_in_mem(char const *filepath, char *buffer, int size);
char *file_to_buffer(char *filepath, int size);
char **malloc_tab(char **tab, char *buffer, lab_t *maze);
char **load_map(char **map, char *filepath, lab_t *maze);
int **init_int(int **mappint, lab_t *maze);
int **set_obstacle(int **mappint, char **map, lab_t *maze);
int **find_and_set(int **mappint, char **map, lab_t *maze);
int **draw_ints(char **map, int **mappint, lab_t *maze);
int is_next(lab_t *maze, int *pos, int number);
char **replace_number(int number, lab_t *maze);
int size_of_buffer(char *filepath);
int strline(char *buffer);
int nb_of_line(char *buffer);

#endif
