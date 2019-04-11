/*
** EPITECH PROJECT, 2019
** generator.h
** File description:
** gen
*/

#ifndef GEN_H
#define GEN_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include "struct_gen.h"

#define ERROR_NUM 84

//create_map.c
int **create_map(gen_t *gen);

//utils.c
int my_atoi(char *str);
int str_compare(char *str1, char *str2);
int my_strlen(char *str);
int my_strlen_tab(char **tab);
int my_strlen_tab_int(int *tab);

//verif.c
int take_verif_size(char **av, gen_t *gen);

//main.c

//finsih_imperfection.c
void create_map_in_str(gen_t *gen);
void check_go_finsh(gen_t *gen);
int put_imperfection(gen_t *gen);

//back_tracking
int gen_path(gen_t *gen);
int check_tab_mouv(int *tab);

//second algo
void change_map_second(gen_t *gen);

#endif