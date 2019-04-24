/*
** EPITECH PROJECT, 2019
** Navy
** File description:
** connect players
*/

#include "../header.h"

void get_pid(int pid, siginfo_t *info, void *jsp)
{
    global = info->si_pid;
}

void player1start(int local_pid, struct sigaction signal)
{
    my_putstr("my_pid: ");
    my_put_nbr(local_pid);
    my_putstr("\nwaiting for enemy connection...\n\n");
    signal.sa_flags = SA_SIGINFO;
    signal.sa_sigaction = get_pid;
    sigaction(SIGUSR1, &signal, NULL);
    pause();
    my_putstr("enemy connected\n\n");
    kill(global, SIGUSR1);
}

void player2start(int local_pid, int other_pid, struct sigaction signal)
{
    my_putstr("my_pid: ");
    my_put_nbr(local_pid);
    kill(other_pid, SIGUSR1);
    signal.sa_flags = SA_SIGINFO;
    signal.sa_sigaction = get_pid;
    sigaction(SIGUSR1, &signal, NULL);
    pause();
    my_putstr("\nsuccessfully connected\n\n");
}

int connect(int local_pid, int other_pid)
{
    struct sigaction signal;

    if (other_pid == 0)
        player1start(local_pid, signal);
    else
        player2start(local_pid, other_pid, signal);
    return (global);
}
