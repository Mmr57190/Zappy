/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** pnw
*/

#include "../../include/server.h"

void send_all_to_gui(zappy_t *zap, client_t *cl, char *buffer)
{
    int err = 0;

    for (int j = 0; j < MAX_CLIENTS; j++)
        if (zap->clients[j].fd != -1 &&
        strcmp(zap->clients[j].team, "graphic") != 0) {
            err = snprintf(buffer, BUFFER_SIZE, "pnw #%d %d %d %c %d %s\n",
            zap->clients[j].fd, zap->clients[j].posX, zap->clients[j].posY,
            zap->clients[j].orientation, zap->clients[j].level,
            zap->clients[j].team);
            check_snprintf(err, cl, buffer);
        }
}

void send_to_all_gui(zappy_t *zap, client_t *cl, char *buffer)
{
    for (int j = 0; j < MAX_CLIENTS; j++)
        if (zap->clients[j].fd != -1 &&
        strcmp(zap->clients[j].team, "graphic") == 0 &&
        strcmp(cl->team, "graphic") != 0)
            send_response(zap->clients[j].fd, buffer);
}

void pnw(zappy_t *zap, client_t *cl)
{
    char buffer[BUFFER_SIZE];
    int err = 0;

    err = snprintf(buffer, BUFFER_SIZE, "pnw #%d %d %d %c %d %s\n",
    cl->fd, cl->posX, cl->posY, cl->orientation, cl->level, cl->team);
    if (err == -1) {
        send_response(cl->fd, "ko\n");
        return;
    }
    if (strcmp(cl->team, "graphic") == 0) {
        send_all_to_gui(zap, cl, buffer);
        mct(zap, cl, NULL);
    } else {
        send_to_all_gui(zap, cl, buffer);
    }
}
