/*
** EPITECH PROJECT, 2019
** sokoban.c
** File description:
** main
*/

#include "sokoban.h"
#include "my.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    char *map;

    if (argc != 2)
        return (84);

    if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
        printhelper();
        return (0);}

    map = get_read(argv[1]);
    if (map == NULL)
        return (84);
    if (error_handling(map) == false)
        return (84);
    if (my_sokoban(map) == ' ')
        main(argc, argv);

    free(map);
    return (0);
}

void printhelper(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map  file representing the warehouse map, containing ");
    my_putstr("‘#’ for walls, \n");
    my_putstr("          ‘P’ for the player, ‘X’ ");
    my_putstr("for boxes and ‘O’ for storage locations.\n");
}