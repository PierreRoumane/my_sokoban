/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** check_positive
*/

#include "my.h"
#include "sokoban.h"

bool check_positive(char *map, int pos_i)
{
    int i, count_n = 0;

    for (i = pos_i; i != 0; i--)
    {
        if (map[i] == '\n')
            count_n++;
    }
    if (count_n >= 2)
        return (true);
    return (false);
}