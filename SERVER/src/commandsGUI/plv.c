/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** plv
*/

#include "../../include/server.h"

void plv(zappy_t *zap, client_t *client, char *arg)
{
    char buffer[BUFFER_SIZE];
    int err = 0;
    int id = 0;

    if (arg == NULL)
        return (send_response(client->fd, "ko\n"));
    id = arg[1] - '0';
    for (int i = 0; i < zap->nbClients; i++) {
        if (zap->clients[i].fd == id) {
            err = snprintf(buffer, BUFFER_SIZE, "plv %d %d\n", \
            zap->clients[i].fd, zap->clients[i].level);
            check_snprintf(err, client, buffer);
            return;
        }
    }
    send_response(client->fd, "ko\n");
}
