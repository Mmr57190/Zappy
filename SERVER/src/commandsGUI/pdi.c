/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** pdi
*/

#include "../../include/server.h"

void pdi(zappy_t *zap, client_t *cl)
{
    char buffer[BUFFER_SIZE];
    int err = 0;

    err = snprintf(buffer, BUFFER_SIZE, "pdi %d\n", cl->fd);
    if (err < 0) {
        send_response(cl->fd, "ko\n");
        return;
    }
    for (int j = 0; j < MAX_CLIENTS; j++)
        if (zap->clients[j].fd != -1 &&
        strcmp(zap->clients[j].team, "graphic") == 0 &&
        strcmp(cl->team, "graphic") != 0)
            send_response(zap->clients[j].fd, buffer);
}
