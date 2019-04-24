/*
** EPITECH PROJECT, 2019
** game.c
** File description:
** game
*/

#include "../header.h"

int check_win(char *map)
{
    int nb_x = 0;
    int i = 0;

    while (map[i] != '\0') {
        if (map[i] == 'x')
            nb_x = nb_x + 1;
        i = i + 1;
    }
    if (nb_x == 14)
        return (1);
    else
        return (0);
}

int check_x(char *map1, char *map2)
{
    if (check_win(map1) == 1) {
        my_putstr("Enemy won\n\n");
        return (1);
    }
    if (check_win(map2) == 1) {
        my_putstr("I won\n\n");
        return (0);
    }
    return (2);
}

void disp_with_turn(char *map1, char *map2, int disp)
{
    if (disp % 2 == 0) {
        my_putstr("my positions:\n");
        my_putstr(map1);
        my_putstr("\nenemy's positions:\n");
        my_putstr(map2);
        my_putchar('\n');
    }
}

int loop(char *map1, char *map2, int pid1, int pid2)
{
    int eval = 2;
    int turn = 0;
    int disp = 0;

    if (pid2 == 0)
        turn = 1;
    pid2 = connect(pid1, pid2);
    while (eval == 2) {
        if (turn % 2 == 1) {
            disp_with_turn(map1, map2, disp);
            your_turn(map2, pid1, pid2);
        } else {
            disp_with_turn(map1, map2, disp);
            other_turn(map1, map2, pid1, pid2);
        }
        eval = check_x(map1, map2);
        turn = turn + 1;
        disp = disp + 1;
    }
    return (eval);
}

int game(char *path, char *pid)
{
    char *map1 = NULL;
    char *map_empt = map();
    int fd = open(path, O_RDONLY);
    char *pos = malloc(sizeof(char)*READ_SIZE);
    int pid1 = getpid();
    int pid2 = my_getnbr(pid);


    if (map_empt == NULL)
        return (84);
    if (fd == -1)
        return (84);
    if ((read(fd, pos, READ_SIZE)) == -1)
        return (84);
    map1 = creat_map_with_pos(map(), pos);
    if (map_is_good(map1) == 0)
        return (loop(map1, map(), pid1, pid2));
    else
        return (84);
}
