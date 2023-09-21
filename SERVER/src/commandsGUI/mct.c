/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** mct
*/

#include "../../include/server.h"

static void mct_send(zappy_t *zap, client_t *cl, int x, int y)
{
    char buffer[BUFFER_SIZE];
    int err = 0;

    err = snprintf(buffer, BUFFER_SIZE,"bct %d %d %d %d %d %d %d %d %d\n",
        x, y, zap->map->tile[y][x].food,
        zap->map->tile[y][x].linemate, zap->map->tile[y][x].deraumere,
        zap->map->tile[y][x].sibur, zap->map->tile[y][x].mendiane,
        zap->map->tile[y][x].phiras, zap->map->tile[y][x].thystame);
    if (err == -1)
        send_response(cl->fd, "ko\n");
    else
        send_response(cl->fd, buffer);
}

void mct(zappy_t *zap, client_t *cl, char *position)
{
    int err = 0;

    for (int y = 0; y < zap->map->y; y++)
        for (int x = 0; x < zap->map->x; x++)
            mct_send(zap, cl, x, y);
}
