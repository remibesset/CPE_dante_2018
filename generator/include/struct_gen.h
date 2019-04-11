/*
** EPITECH PROJECT, 2019
** structure of gen
** File description:
** struct
*/

#ifndef STRUCT_H
#define STRUCT_H

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

#define SIZE 8

typedef struct coord_s
{
    int x;
    int y;
}coord_t;

typedef struct gen_s
{
    coord_t size;
    coord_t start;
    coord_t end;
    coord_t pos_gen;
    char **map;
    int imperfection;
}gen_t;

#endif