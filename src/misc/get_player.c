/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** get_player
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include "sokoban.h"

void find_player(player_s *player, char *map)
{
    int pos_x = 0, pos_y = 0, lenght;

    for (lenght = 0; map[lenght] != '\n'; lenght++);
    player->lenght = lenght + 1;
    for (int i = 0; map[i] != '\0'; i++)
    {
        pos_x++;
        if (map[i] == 'P') {
            player->pos_x = pos_x - 1;
            player->pos_y = pos_y;
            player->pos_i = i;
        }
        if (map[i] == '\n') {
            pos_x = 0;
            pos_y++; }
    }
}