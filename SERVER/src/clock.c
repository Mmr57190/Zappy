/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** clock
*/

#include "../include/server.h"
#include <time.h>

int get_time(zappy_t *zap)
{
    float seconds = 1000 / zap->freq;
    time_t start;

    start = time(0);
    if (time(0) - start == seconds)
        return (1);
    return (0);
}

void move_cmdtime(zappy_t *zap)
{
    zap->cmdTime[0] = zap->cmdTime[1];
    zap->cmdTime[1] = zap->cmdTime[2];
    zap->cmdTime[2] = zap->cmdTime[3];
    zap->cmdTime[3] = zap->cmdTime[4];
    zap->cmdTime[4] = zap->cmdTime[5];
    zap->cmdTime[5] = zap->cmdTime[6];
    zap->cmdTime[6] = zap->cmdTime[7];
    zap->cmdTime[7] = zap->cmdTime[8];
    zap->cmdTime[8] = zap->cmdTime[9];
    zap->cmdTime[9] = -1;
}

void less_cmdtime(zappy_t *zap)
{
    zap->cmdTime[0]--;
}
