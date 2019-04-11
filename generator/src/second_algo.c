/*
** EPITECH PROJECT, 2019
** second algo
** File description:
** second algo
*/

#include "generator.h"

void change_map_second(gen_t *gen)
{
    for (int i = 0; i < gen->size.y - 1; i++) {
        for (int j = 0; j < gen->size.x - 1; j++) {
            gen->map[i][j] = ((i % 2) == 0) ? '2' : '3';
        }
        if ((i % 2) == 1 && i != gen->size.y - 2)
            gen->map[i][rand() % (gen->size.x - 1)] = '2';
    }
    gen->map[gen->end.y - 1][gen->end.x - 1] = '2';
}