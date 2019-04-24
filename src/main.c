/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main of navy
*/

#include "../header.h"

int check_line(char *line, int nb_line)
{
    int i_pos = nb_line * 8;

    if (line[i_pos + 1] != ':' && line [i_pos + 4] != ':')
        return (1);
    if (line[i_pos + 7] != '\n' && line[i_pos + 7] != '\0')
        return (1);
    if (line[i_pos + 2] < 'A' || line[i_pos + 2] > 'H')
        return (1);
    if (line[i_pos + 3] < '1' || line[i_pos + 3] > '8')
        return (1);
    if (line[i_pos + 5] < 'A' || line[i_pos + 5] > 'H')
        return (1);
    if (line[i_pos + 6] < '1' || line[i_pos + 6] > '8')
        return (1);
    if (line[i_pos] != (nb_line + 2) + 48)
        return (1);
    return (good_size_boat(line, i_pos));
}

int test_pos(char *str)
{
    int nb_line = 0;

    while (nb_line != 4) {
        if (check_line(str, nb_line) == 0)
            nb_line = nb_line + 1;
        else
            return (84);
    }
    return (0);
}

int open_pos(char *path)
{
    char *line = malloc(sizeof(char)*32);
    int fd = 0;

    fd = open(path, O_RDONLY);
    if (fd == -1)
        return (84);
    if (read(fd, line, 32) == -1 || !line)
        return (84);
    if (test_pos(line) == 0)
        return (0);
    else
        return (84);
}

int put_help(int val)
{
    if (val == 1)
        my_putstr("try with -h\n");
    if (val == 2) {
        my_putstr("USAGE\n./navy [first_player_pid] navy_positions\n");
        my_putstr("DESCRIPTION\nfirst_player_pid: only for the 2nd player");
        my_putstr(". pid of the first player. pid of the first player.\n");
        my_putstr("navy_positions: file representing the positions of ");
        my_putstr("the ships.\n");
    }
    return (84);
}

int main(int argc, char **argv)
{
    if (argc > 3 || argc < 2)
        return (put_help(1));
    if (argv[1][0] == '-' && argv[1][1] == 'h')
        return (put_help(2));
    if (argc == 2 && open_pos(argv[1]) == 0)
        return (game(argv[1], "0"));
    if (argc == 3 && open_pos(argv[2]) == 0)
        return (game(argv[2], argv[1]));
    else
        return (put_help(1));

}
