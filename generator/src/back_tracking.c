/*
** EPITECH PROJECT, 2019
** back_tracking
** File description:
** backtraking
*/

#include "generator.h"

void add_possibilities(gen_t *gen, int **tab)
{
    if (gen->pos_gen.y - 2 >= 0) {
        if (gen->map[gen->pos_gen.y - 2][gen->pos_gen.x] != 2)
            (*tab)[0] = 1;
    }
    if (gen->pos_gen.y + 2 <= gen->size.y - 1) {
        if (gen->map[gen->pos_gen.y + 2][gen->pos_gen.x] != 2)
            (*tab)[1] = 1;
    }
    if (gen->pos_gen.x + 2 <= gen->size.x - 1) {
        if (gen->map[gen->pos_gen.y][gen->pos_gen.x + 2] != 2)
            (*tab)[2] = 1;
    }
    if (gen->pos_gen.x - 2 >= 0) {
        if (gen->map[gen->pos_gen.y][gen->pos_gen.x - 2] != 2)
            (*tab)[3] = 1;
    }
}

void make_path(gen_t *gen, int x, int y)
{
    if (gen->map[gen->pos_gen.y + y][gen->pos_gen.x + x] != 2) {
        gen->map[gen->pos_gen.y + y][gen->pos_gen.x + x] = 2;
        if (x != 0)
            gen->map[gen->pos_gen.y][gen->pos_gen.x + (x / 2)] = 2;
        else if (y != 0)
            gen->map[gen->pos_gen.y + (y / 2)][gen->pos_gen.x] = 2;
        gen->pos_gen.y += y;
        gen->pos_gen.x += x;
    }
}

int *create_tab_moove(int *j, int **tab)
{
    int *tab_moove = malloc(sizeof(int) * 4);

    for (int k = 0; k < 4; tab_moove[k] = -1, k++);
    for (int k = 0; k < 4; k++)
        if ((*tab)[k] == 1)
            tab_moove[(*j)++] = k;
    for (int k = *j; k < 4; tab_moove[k] = -1, k++);
    return (tab_moove);
}

int random_route(gen_t *gen, int **tab)
{
    int random_max = 0;
    int j = 0;
    int pass = 0;
    int *tab_oui = create_tab_moove(&j, tab);

    random_max = rand() % j;
    j = tab_oui[random_max];
    switch_direction(j, gen);
    (*tab)[j] = 0;
    free(tab_oui);
    gen_path(gen);
    return (0);
}

int gen_path(gen_t *gen)
{
    int *tab = malloc(sizeof(int) * 4);
    int posx = gen->pos_gen.x;
    int posy = gen->pos_gen.y;

    for (int i = 0; i < 4; tab[i] = 0, i++);
    add_possibilities(gen, &tab);
    while (42) {
        if (check_tab_mouv(tab) == 1) {
            free(tab);
            break;
        } else {
            random_route(gen, &tab);
            gen->pos_gen.x = posx;
            gen->pos_gen.y = posy;
        }
    }
    return (0);
}