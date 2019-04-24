/*
** EPITECH PROJECT, 2019
** your_turn.c
** File description:
** your_turn
*/

#include "../header.h"

void signal_i_pos(int i, int my_pid, int other_pid)
{
    while (i != 0) {
        kill(other_pid, SIGUSR1);
        usleep(1000);
        i = i - 1;
    }
    kill(other_pid, SIGUSR2);
}

int check_good_pos(char *cmd)
{
    if (cmd[0] < 'A' || cmd[0] > 'H')
        return (1);
    if (cmd[1] < '1' || cmd[1] > '8')
        return (1);
    return (0);
}

char *read_pos(void)
{
    char *cmd = malloc(sizeof(char)*3);

    if (cmd != NULL) {
        while (1) {
            my_putstr("attack: ");
            if (read(0, cmd, 3) == 3) {
                cmd[2] = '\0';
                if (check_good_pos(cmd) == 0)
                    return (cmd);
            }
            my_putstr("wrong position\n");
        }
    }
    return (NULL);
}

void your_turn(char *map2, int my_pid, int other_pid)
{
    char *pos = read_pos();
    int i_pos = ((pos[0] - 64) * 2) + ((pos[1] - 48) * 18 + 18);

    signal_i_pos(i_pos, my_pid, other_pid);
    put_the_hit(pos, map2, i_pos);
}
