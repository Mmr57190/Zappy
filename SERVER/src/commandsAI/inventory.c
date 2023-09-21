/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** Inventory
*/

#include "../../include/server.h"

void inventory(zappy_t *zap, client_t *cl, char *message)
{
    char buffer[BUFFER_SIZE];
    int err = 0;

    err = snprintf(buffer, BUFFER_SIZE,"[food %d, linemate %d, deraumere %d, "
    "sibur %d, mendiane %d, phiras %d, thystame %d]\n", cl->food, \
    cl->linemate, cl->deraumere, cl->sibur, cl->mendiane, cl->phiras, \
    cl->thystame);
    if (err < 0)
        send_response(cl->fd, "ko\n");
    else
        send_response(cl->fd, buffer);
}
