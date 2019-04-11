/*
** EPITECH PROJECT, 2019
** create_map
** File description:
** create map
*/

#include "generator.h"

char **create_map(gen_t *gen)
{
    int i = 0;
    char **map = xmalloc(sizeof(char *) * (gen->size.y));

    for (i = 0; i < gen->size.y; i++) {
        map[i] = xmalloc(sizeof(char) * (gen->size.x));
    }
    for (int i = 0; i < gen->size.y; i++)
        for (int j = 0; j < gen->size.x; j++) {
            map[i][j] = (i % 2 == 0 && j % 2 == 0) ? '1' : '3';
        }
    gen->map = map;
    gen->map[gen->end.y][gen->end.x] = '2';
    return (0);
}