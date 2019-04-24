/*
** EPITECH PROJECT, 2018
** header.h
** File description:
** header file
*/

#ifndef MY_HEADER_
#define MY_HEADER_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef READ_SIZE
#define READ_SIZE (1024)
#endif /*READ_SIZE*/

int global;

int my_getnbr(char const *str);
void my_putchar(char const c);
void my_put_nbr(int nbr);
void my_putstr(char *str);
int my_strlen(char const *str);

int main(int argc, char **argv);
int open_pos(char *path);
char *map(void);
void get_pid(int pid, siginfo_t *info, void *jsp);
void player1start(int local_pid, struct sigaction signal);
void player2start(int local_pid, int other_pid, struct sigaction signal);
int connect(int local_pid, int other_pid);
char *read_pos(void);
void signal_i_pos(int i, int my_pid, int other_pid);
void get_hit(int pid, siginfo_t *info, void *jsp);
void get_plouf(int pid, siginfo_t *info, void *jsp);
void put_the_hit(char *pos, char *map2, int i_pos);
void your_turn(char *map2, int my_pid, int other_pid);
int capt_tics(int other_pid);
char *pos_with_i_pos(int i_pos, char *map);
void other_turn(char *map1, char *map2, int my_pid, int other_pid);
void get_stop(int pid, siginfo_t *info, void *jsp);
void get_no(int pid, siginfo_t *info, void *jsp);
char *open_path(char *path);

int good_size_boat(char *line, int i_pos);
int game(char *pathpos, char *pid);
int loop(char *map1, char *map2, int pid1, int pid2);
char *creat_map_with_pos(char *map, char *pos);
void interval_boat1(int pos1, int pos2, int size, char *map);
int check_x(char *map1, char *map2);
int check_good_pos(char *cmd);
int map_is_good(char *map);

#endif /*MY_HEADER_*/
