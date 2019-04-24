/*
** EPITECH PROJECT, 2019
** Navy
** File description:
** open file function
*/

#include "../header.h"

int add_in(char *map, char *in, int i)
{
    int j = 0;

    while (in[j] != '\0') {
        map[i] = in[j];
        i = i + 1;
        j = j + 1;
    }
    return (i);
}

char *map(void)
{
    char *map = malloc(sizeof(char)*181);
    int i = 0;

    i = add_in(map, " |A B C D E F G H\n", i);
    i = add_in(map, "-+---------------\n", i);
    i = add_in(map, "1|. . . . . . . .\n", i);
    i = add_in(map, "2|. . . . . . . .\n", i);
    i = add_in(map, "3|. . . . . . . .\n", i);
    i = add_in(map, "4|. . . . . . . .\n", i);
    i = add_in(map, "5|. . . . . . . .\n", i);
    i = add_in(map, "6|. . . . . . . .\n", i);
    i = add_in(map, "7|. . . . . . . .\n", i);
    i = add_in(map, "8|. . . . . . . .\n", i);
    map[i] = '\0';
    return (map);
}

char *open_path(char *path)
{
    char *str = malloc(sizeof(char)*READ_SIZE);
    int fd = open(path, O_RDONLY);

    if (fd == -1)
        return (NULL);
    if (read(fd, str, READ_SIZE) == -1)
        return (NULL);
    return (str);
}
