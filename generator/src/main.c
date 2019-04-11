/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include "generator.h"

void make_maze(gen_t *gen, int imperfection)
{
    srand(time(NULL));
    gen->map[gen->start.x][gen->start.y] = 2;
    gen->pos_gen = (coord_t) gen->start;
    gen->imperfection = imperfection;
    gen_path(gen);
    check_go_finsh(gen);
    if (imperfection == 1) {
        put_imperfection(gen);
    }
    create_map_in_str(gen);
}

int main(int ac, char **av)
{
    gen_t gen;

    if (ac == 3 || (ac == 4 && str_compare(av[3], "imperfect") == 1)) {
        if (take_verif_size(av, &gen) == ERROR_NUM)
            return (ERROR_NUM);
        make_maze(&gen, 0);
    } else if (ac == 4 && str_compare(av[3], "perfect") == 1) {
        if (take_verif_size(av, &gen) == ERROR_NUM)
            return (ERROR_NUM);
        make_maze(&gen, 1);
    } else
        return (ERROR_NUM);
    return (0);
}
