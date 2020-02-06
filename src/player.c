/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** player.c
*/

#include <ncurses.h>
#include <unistd.h>
#include "sokoban.h"

void movement(player_s *player, int character, char *map)
{
    if (character == KEY_RIGHT)
        movement_right(player, map);
    if (character == KEY_LEFT)
        movement_left(player, map);
    if (character == KEY_DOWN)
        movement_down(player, map);
    if (character == KEY_UP)
        movement_up(player, map);
}

void movement_right(player_s *player, char *map)
{
    if (map[player->pos_i + 1] == 'X'
    && map[player->pos_i + 2] != 'X'
    && map[player->pos_i + 2] != '#') {
            map[player->pos_i + 2] = 'X';
            map[player->pos_i + 1] = ' ';
            player->pos_i++;
            player->pos_x++;
        }
    else if (map[player->pos_i + 1] != '#'
    && (map[player->pos_i + 1] != 'X')) {
        player->pos_i++;
        player->pos_x++;
    }
}

void movement_left(player_s *player, char *map)
{
    if (map[player->pos_i - 1] == 'X'
    && map[player->pos_i - 2] != 'X'
    && map[player->pos_i - 2] != '#') {
            map[player->pos_i - 2] = 'X';
            map[player->pos_i - 1] = ' ';
            player->pos_i--;
            player->pos_x--;
        }
    else if (map[player->pos_i - 1] != '#'
    && map[player->pos_i - 1] != 'X') {
        player->pos_i--;
        player->pos_x--;
    }
}

void movement_up(player_s *player, char *map)
{
    if (check_positive(map, player->pos_i) == true) {
        if (map[player->pos_i - player->lenght] == 'X'
        && map[player->pos_i - (player->lenght * 2)]
        != 'X' && map[player->pos_i -
        (player->lenght * 2)] != '#') {
                map[player->pos_i -
                player->lenght * 2] = 'X';
                map[player->pos_i-player->lenght] = ' ';
                player->pos_i = player->pos_i -
                player->lenght;
                player->pos_y--; } }
    else if (check_positive(map, player->pos_i) == false) {
        if (map[player->pos_i - player->lenght] == 'X'){
                map[player->pos_i-player->lenght] = ' ';
                player->pos_i = player->pos_i -
                player->lenght;
                player->pos_y--; } }
    if (map[player->pos_i - player->lenght] != '#'
    && map[player->pos_i - player->lenght] != 'X') {
        player->pos_i = player->pos_i - player->lenght;
        player->pos_y--; }
}

void movement_down(player_s *player, char *map)
{
    if (map[player->pos_i +
    player->lenght] == 'X'
    && map[player->pos_i +
    (player->lenght * 2)] != 'X'
    && map[player->pos_i +
    (player->lenght * 2)] != '#') {
            map[player->pos_i +
            player->lenght * 2] = 'X';
            map[player->pos_i +
            player->lenght] = ' ';
            player->pos_i = player->pos_i +
            player->lenght;
            player->pos_y++; }
    else if (map[player->pos_i +
    player->lenght] != '#'
    && map[player->pos_i +
    player->lenght] != 'X') {
        player->pos_i = player->pos_i +
        player->lenght;
        player->pos_y++; }
}