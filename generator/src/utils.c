/*
** EPITECH PROJECT, 2019
** utils
** File description:
** utils function
*/

#include "generator.h"

int str_compare(char *str1, char *str2)
{
    int count = 0;
    int len_str = my_strlen(str2);

    for (int i = 0; str2[i] != '\0' && str1[i] != '\0'; i++)
        if (str2[i] == str1[i])
            count++;
    if (count == len_str)
        return (1);
    return (0);
}

int my_atoi(char *str)
{
    int result = 0;
    int i = 0;
    int sub = 0;

    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result);
}

int my_strlen(char *str)
{
    int i = 0;
    if (str == NULL)
        return (0);
    for (int i = 0; str[i] != '\0'; i++);
    return (i);
}

int my_strlen_tab(char **tab)
{
    int i = 0;

    for (i; tab[i] != 0; i++);
    return (i);
}

int my_strlen_tab_int(int *tab)
{
    int i = 0;

    for (i; tab[i] != -1; i++);
    return (i);
}