/*
** EPITECH PROJECT, 2019
** sokoban.h
** File description:
** header for sokoban
*/

#include "my.h"

typedef struct player_t
{
    int pos_i;
    int pos_x;
    int pos_y;
    int lenght;
} player_s;

//getread.c
char *get_read(char *filename);

//my_sokoban.c
char my_sokoban(char *map);
void curses_init(void);
bool check_win(char *map);

//player.c
void movement(player_s *player, int input, char *map);
void movement_right(player_s *player, char *map);
void movement_left(player_s *player, char *map);
void movement_down(player_s *player, char *map);
void movement_up(player_s *player, char *map);

//main.c
void printhelper(void);

//error_handling.c
bool error_handling(char *map);
bool check_map(char *map);

//get_calc.c
void get_base(char *map);

//get_lenght_line.c
int get_lenght_line_up(char *map, int starter);
int get_lenght_line_down(char *map, int starter);

//get_player.c
void find_player(player_s *player, char *map);

//check_positive.c
bool check_positive(char *map, int pos_i);
void check_position_false(player_s *player, char *map);
void check_position_true(player_s *player, char *map);