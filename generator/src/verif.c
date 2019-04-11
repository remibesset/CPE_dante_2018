/*
** EPITECH PROJECT, 2019
** verifictaion
** File description:
** verfitcation function
*/

#include "generator.h"

int take_verif_size(char **av, gen_t *gen)
{
    int x = 0;
    int y = 0;

    gen->start.x = 0;
    gen->start.y = 0;
    if ((x = my_atoi(av[1])) > 0) {
        gen->end.x = x - 1;
        gen->size.x = x;
    } else
        return (ERROR_NUM);
    if ((y = my_atoi(av[2])) > 0) {
        gen->end.y = y - 1;
        gen->size.y = y;
    } else
        return (ERROR_NUM);
    create_map(gen);
    return (0);
}

void *xmalloc(int size)
{
    void *ptr = malloc(size);
    char err_msg[] = "Malloc failed !\n";

    if (ptr == NULL) {
        write(1, err_msg, my_strlen(err_msg));
        exit(84);
    }
    return (ptr);
}