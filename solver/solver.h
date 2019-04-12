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
#include <time.h>

#ifndef SOLVER_H_
#define SOLVER_H_

typedef struct lab_s
{
    char **map;
    char *buffer;
    int size_x;
    int size_y;
    int **mi;
    int number;
    int nb;
    int ite;
    int actnb;
    int verif;
} lab_t;

char *load_file_in_mem(char const *filepath, char *buffer, int size);
char *file_to_buffer(char *filepath, int size);
void malloc_tab(lab_t *maze);
void load_map(char *filepath, lab_t *maze);
void init_int(lab_t *maze);
int size_of_buffer(char *filepath);
int strline(char *buffer);
int nb_of_line(char *buffer);
int nb_of_number(lab_t *maze);
void draw_moves(lab_t *maze);
void error_impossible(void);
void set_way(lab_t *maze, int i, int j);

#endif
