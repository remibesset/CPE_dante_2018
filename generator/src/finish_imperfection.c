/*
** EPITECH PROJECT, 2019
** finish and imperfection
** File description:
** Map display
*/

#include "generator.h"

void check_go_finsh(gen_t *gen)
{
    int chiffre_rand = rand() % 2;

    if (gen->map[gen->end.y][gen->end.x - 1] == 2)
        gen->map[gen->end.y][gen->end.x] = 2;
    else if (gen->map[gen->end.y - 1][gen->end.x - 1] == 2) {
        if (chiffre_rand == 0) {
            gen->map[gen->end.y][gen->end.x] = 2;
            gen->map[gen->end.y - 1][gen->end.x] = 2;
        } else if (chiffre_rand == 1) {
            gen->map[gen->end.y][gen->end.x] = 2;
            gen->map[gen->end.y][gen->end.x - 1] = 2;
        }
    }
}

int put_imperfection_condition(gen_t *gen, int i, int j, int rand_nbr)
{
    if (gen->map[i][j] == 3) {
        rand_nbr = rand() % 3;
        gen->map[i][j] = (rand_nbr == 0) ? 2 : 3;
    }
    return (0);
}

int put_imperfection(gen_t *gen)
{
    int rand_nbr = 0;

    for (int i = 0; i < gen->size.y; i++)
        for (int j = 0; j < gen->size.x; j++)
            put_imperfection_condition(gen, i, j, rand_nbr);
    return (0);
}

void create_map_in_str(gen_t *gen)
{
    char *map = malloc(sizeof(char) * \
    (gen->size.x * gen->size.y + gen->size.y + 1));
    int k = 0;

    for (int i = 0; i < gen->size.y; i++) {
        if (i != 0)
            map[k++] = '\n';
        for (int j = 0; j < gen->size.x; j++)
            map[k++] = (gen->map[i][j] == 2) ? '*': 'X';
    }
    map[k] = '\0';
    printf(map);
    for (int i = 0; i < gen->size.y - 1; i++)
        free(gen->map[i]);
    free(gen->map);
}