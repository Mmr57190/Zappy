/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** msz
*/

#include "../../include/server.h"

void msz(zappy_t *zappy, client_t *client, char *arg)
{
    char buffer[BUFFER_SIZE];
    int err = 0;

    err = snprintf(buffer, BUFFER_SIZE, "msz %d %d\n", zappy->map->x, \
    zappy->map->y);
    if (err < 0)
        send_response(client->fd, "ko\n");
    else
        send_response(client->fd, buffer);
}
