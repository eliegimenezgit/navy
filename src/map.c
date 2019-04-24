/*
** EPITECH PROJECT, 2019
** map.c
** File description:
** map
*/

#include "../header.h"

void interval_boat1(int pos1, int pos2, int size, char *map)
{
    if (size == 3)
        map[(pos1 + pos2) / 2] = size + 48;
    if (size == 4) {
        if (pos2 - pos1 == 6) {
            map[(pos1 + 2)] = size + 48;
            map[(pos1 + 4)] = size + 48;
        }
        if (pos2 - pos1 == 54) {
            map[(pos1 + 18)] = size + 48;
            map[(pos1 + 36)] = size + 48;
        }
    }
}

void interval_boat2(int pos1, int pos2, int size, char *map)
{
    if (size == 5) {
        if (pos2 - pos1 == 72) {
            map[(pos1 + 18)] = size + 48;
            map[(pos1 + 36)] = size + 48;
            map[(pos1 + 54)] = size + 48;
        }
        if (pos2 - pos1 == 8) {
            map[(pos1 + 2)] = size + 48;
            map[(pos1 + 4)] = size + 48;
            map[(pos1 + 6)] = size + 48;
        }
    }
}

char *add_boat(char *map, char *cor)
{
    int size = cor[0] - 48;
    int pos1 = ((cor[2] - 64) * 2) + ((cor[3] - 48) * 18 + 18);
    int pos2 = ((cor[5] - 64) * 2) + ((cor[6] - 48) * 18 + 18);

    if (pos2 < pos1) {
        interval_boat1(pos2, pos1, size, map);
        interval_boat2(pos2, pos1, size, map);
    } else {
        interval_boat1(pos1, pos2, size, map);
        interval_boat2(pos1, pos2, size, map);
    }
    map[pos1] = size + 48;
    map[pos2] = size + 48;
    return (map);
}

char *creat_map_with_pos(char *map, char *pos)
{
    int i = 0;
    int j = 0;
    int count = 0;
    char *line = malloc(sizeof(char)*8);

    while (count < 4) {
        while (pos[i] != '\n' && pos[i] != '\0') {
            line[j] = pos[i];
            j = j + 1;
            i = i + 1;
        }
        add_boat(map, line);
        count = count + 1;
        i = i + 1;
        j = 0;
    }
    return (map);
}
