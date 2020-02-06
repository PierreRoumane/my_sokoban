/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** calc
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "sokoban.h"
#include "my.h"

void get_base(char *map)
{
    for (int i = 0; map[i] != '\0'; i++)
    {
        if (map[i] == 'P')
            map[i] = ' ';
    }
}