/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** pin
*/

#include "../../include/server.h"

void pin(zappy_t *zappy, client_t *client, char *arg)
{
    char buffer[BUFFER_SIZE];
    int id = 0;

    if (arg == NULL)
        return (send_response(client->fd, "ko\n"));
    id = arg[1] - '0';
    for (int i = 0; i < zappy->nbClients; i++) {
        if (zappy->clients[i].fd == id) {
            snprintf(buffer, BUFFER_SIZE, "pin %d %d %d %d %d %d %d %d %d"
            " %d\n", zappy->clients[i].fd, zappy->clients[i].posX,
            zappy->clients[i].posY, zappy->clients[i].food,
            zappy->clients[i].linemate, zappy->clients[i].deraumere,
            zappy->clients[i].sibur, zappy->clients[i].mendiane,
            zappy->clients[i].phiras, zappy->clients[i].thystame);
            send_response(client->fd, buffer);
            return;
        }
    }
}
