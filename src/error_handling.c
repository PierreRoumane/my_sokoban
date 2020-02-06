/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** error_handling
*/

#include "my.h"
#include "sokoban.h"

bool error_handling(char *map)
{
    if (check_map(map) == false)
        return (false);
    return (true);
}

bool check_map(char *map)
{
    for (int i = 0; map[i] != '\0'; i++)
    {
        if (map[i] != 'X' && map[i] != '#' && map[i] != ' ' && map[i] != '\n'
        && map[i] != 'P' && map[i] != 'O' && map[i] != '\0')
        return (false);
    }
    return (true);
}