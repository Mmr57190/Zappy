/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** bct
*/

#include "../../include/server.h"

void bct(zappy_t *zap, client_t *cl, char *position)
{
    int x = atoi(strtok(position, " "));
    int y = atoi(strtok(NULL, " "));
    int err = 0;

    if (x < 0 || x >= zap->map->x || y < 0 || y >= zap->map->y) {
        send_response(cl->fd, "ko\n");
    } else {
        char buffer[BUFFER_SIZE];
        err = snprintf(buffer, BUFFER_SIZE,"bct %d %d %d %d %d %d %d %d %d\n",
        x, y, zap->map->tile[y][x].food, zap->map->tile[y][x].linemate,
        zap->map->tile[y][x].deraumere, zap->map->tile[y][x].sibur,
        zap->map->tile[y][x].mendiane, zap->map->tile[y][x].phiras,
        zap->map->tile[y][x].thystame);
        if (err == -1)
            send_response(cl->fd, "ko\n");
        else
            send_response(cl->fd, buffer);
    }
}
