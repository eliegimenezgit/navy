/*
** EPITECH PROJECT, 2019
** other_turn.c
** File description:
** other_turn
*/

#include "../header.h"

char *pos_with_i_pos(int i_pos, char *map)
{
    char *pos = malloc(sizeof(char)*3);
    int i = i_pos;

    while (map[i] < '1' || map[i] > '8') {
        i = i - 1;
    }
    pos[1] = map[i];
    while (map[i_pos] < 'A' || map[i_pos] > 'H') {
        i_pos = i_pos - 18;
    }
    pos[0] = map[i_pos];
    pos[2] = '\0';
    return (pos);
}

void get_no(int pid, siginfo_t *info, void *ucontext)
{
}

void get_stop(int pid, siginfo_t *info, void *ucontext)
{
    global = 1;
}

int capt_tics(int other_pid)
{
    int i_pos = 0;
    struct sigaction signal;
    struct sigaction signal2;

    global = 0;
    my_putstr("waiting for enemy's attack...\n");
    while (global == 0) {
        signal.sa_flags = SA_SIGINFO;
        signal2.sa_flags = SA_SIGINFO;
        signal.sa_sigaction = get_no;
        signal2.sa_sigaction = get_stop;
        sigaction(SIGUSR1, &signal, NULL);
        sigaction(SIGUSR2, &signal2, NULL);
        pause();
        i_pos = i_pos + 1;
    }
    return (i_pos - 1);
}

void other_turn(char *map1, char *map2, int my_pid, int other_pid)
{
    int i_pos = capt_tics(other_pid);
    char *pos = pos_with_i_pos(i_pos, map2);

    my_putstr(pos);
    if (map1[i_pos] == '.' || map1[i_pos] == 'o') {
        my_putstr(": missed\n\n");
        kill(other_pid, SIGUSR2);
        map1[i_pos] = 'o';
    } else {
        my_putstr(": hit\n\n");
        kill(other_pid, SIGUSR1);
        map1[i_pos] = 'x';
    }
}
