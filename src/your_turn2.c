/*
** EPITECH PROJECT, 2019
** your_turn2.c
** File description:
** your_turn
*/

#include "../header.h"

void get_hit(int pid, siginfo_t *info, void *jsp)
{
    global = 1;
    my_putstr(": hit\n\n");
}

void get_plouf(int pid, siginfo_t *info, void *jsp)
{
    global = 2;
    my_putstr(": missed\n\n");
}

void put_the_hit(char *pos, char *map2, int i_pos)
{
    struct sigaction signal;
    struct sigaction signal2;

    my_putstr(pos);
    global = 0;
    signal.sa_flags = SA_SIGINFO;
    signal2.sa_flags = SA_SIGINFO;
    signal.sa_sigaction = get_hit;
    signal2.sa_sigaction = get_plouf;
    sigaction(SIGUSR1, &signal, NULL);
    sigaction(SIGUSR2, &signal2, NULL);
    pause();
    if (global == 1)
        map2[i_pos] = 'x';
    else if (global == 2)
        map2[i_pos] = 'o';
}
