/*
** EPITECH PROJECT, 2019
** good_size_boat.c
** File description:
** yes
*/

#include "../header.h"

int map_is_good(char *map)
{
    int i = 0;
    int b2 = 0;
    int b3 = 0;
    int b4 = 0;
    int b5 = 0;

    while (map[i] != '\0') {
        if (map[i] == '2')
            b2 = b2 + 1;
        if (map[i] == '3')
            b3 = b3 + 1;
        if (map[i] == '4')
            b4 = b4 + 1;
        if (map[i] == '5')
            b5 = b5 + 1;
        i = i + 1;
    }
    if (b2 != 3 || b3 != 4 || b4 != 5 || b5 != 6)
        return (1);
    return (0);
}

int good_size_boat(char *cor, int i)
{
    int size = cor[i] - 48;
    int pos1 = ((cor[i+2] - 64) * 2) + ((cor[i+3] - 48) * 18 + 18);
    int pos2 = ((cor[i+5] - 64) * 2) + ((cor[i+6] - 48) * 18 + 18);

    if (pos2 < pos1) {
        if ((pos1 - pos2) != (size - 1)*18) {
            if ((pos1 - pos2) != (size - 1)*2) {
                return (1);
            }
        }
    } else {
        if ((pos2 - pos1) != (size - 1)*18) {
            if ((pos2 - pos1) != (size - 1)*2) {
                return (1);
            }
        }
    }
    return (0);
}
