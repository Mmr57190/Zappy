/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** utils6
*/

#include "../include/server.h"

void pie_tograph(zappy_t *zap, client_t *cl, int fd)
{
    char str[BUFFER_SIZE];
    int err = 0;

    err = snprintf(str, BUFFER_SIZE, "pie %d %d %d\n", cl->posX, cl->posY, fd);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (zap->clients[i].fd != -1 &&
        strcmp(zap->clients[i].team, "graphic") == 0) {
            check_snprintf(err, &zap->clients[i], str);
        }
    }
}
