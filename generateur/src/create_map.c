/*
** EPITECH PROJECT, 2019
** create_map
** File description:
** create map
*/

#include "generator.h"

int **create_map(gen_t *gen)
{
    int i = 0;
    int **map = malloc(sizeof(int *) * (gen->size.y));

    for (i = 0; i < gen->size.y; i++) {
        map[i] = malloc(sizeof(int) * (gen->size.x));
    }
    for (int i = 0; i < gen->size.y; i++)
        for (int j = 0; j < gen->size.x; j++) {
            map[i][j] = (i % 2 == 0 && j % 2 == 0) ? 1 : 3;
        }
    gen->map = map;
    gen->map[gen->end.y][gen->end.x] = 1;
    return (0);
}