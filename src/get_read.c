/*
** EPITECH PROJECT, 2019
** get_read
** File description:
** open read and send the resulting str back
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "sokoban.h"

char *get_read(char *filename)
{
    int fd, check;
    struct stat *status;
    char *str;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (NULL);
    status = malloc(sizeof(struct stat));
    stat(filename, status);
    str = malloc(sizeof(char) * (status->st_size + 1));
    if (str == NULL)
        return (NULL);
    str[status->st_size] = '\0';

    check = read(fd, str, status->st_size);
    if (check == -1)
        return (NULL);

    free(status);
    return (str);
}