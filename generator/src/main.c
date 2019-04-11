/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include "generator.h"

void make_maze_back_track(gen_t *gen, int imperfection)
{
    srand(time(NULL));
    gen->map[gen->start.x][gen->start.y] = '1';
    gen->pos_gen = (coord_t) gen->start;
    gen->imperfection = imperfection;
    gen_path(gen);
    check_go_finsh(gen);
    if (imperfection == 1) {
        put_imperfection(gen);
    }
    create_map_in_str(gen);
}

void make_maze_second(gen_t *gen, int imperfection)
{
    srand(time(NULL));
    change_map_second(gen);
    check_go_finsh(gen);
    if (imperfection == 1) {
        put_imperfection(gen);
    }
    create_map_in_str(gen);
}

int main(int ac, char **av)
{
    gen_t gen;

    if (ac == 3 || (ac == 4 && str_compare(av[3], "parfect") == 1)) {
        if (take_verif_size(av, &gen) == ERROR_NUM)
            return (ERROR_NUM);
        if (gen.size.x < 950 && gen.size.y < 950)
            make_maze_back_track(&gen, 0);
        else
            make_maze_second(&gen, 0);
    } else if (ac == 4 && str_compare(av[3], "imparfect") == 1) {
        if (take_verif_size(av, &gen) == ERROR_NUM)
            return (ERROR_NUM);
        if (gen.size.x < 950 && gen.size.y < 950)
            make_maze_back_track(&gen, 1);
        else
            make_maze_second(&gen, 1);
    } else
        return (ERROR_NUM);
    return (0);
}
