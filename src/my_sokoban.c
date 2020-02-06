/*
** EPITECH PROJECT, 2019
** popup
** File description:
** bootstrap
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include "sokoban.h"

char my_sokoban(char *map)
{
    bool win = false;
    int input;
    player_s player;

    curses_init();
    find_player(&player, map);
    get_base(map);
    for (int i = 0; input != ' ' && win == false; i++)
    {
        mvprintw(0, 0, map);
        mvprintw(player.pos_y, player.pos_x, "P");
        input = getch();
        movement(&player, input, map);
        win = check_win(map);
        refresh();
    }
    endwin();
    return (input);
}

void curses_init(void)
{
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, true);
    clear();
}

bool check_win(char *map)
{
    for (int i = 0; map[i] != '\0'; i++)
        if (map[i] == 'O')
            return (false);
    return (true);
}