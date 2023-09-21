/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** take3
*/

#include "../../include/server.h"

void event_gui(zappy_t *zap, client_t *cl, int ressource)
{
    char send_pgt[BUFFER_SIZE];
    char send_bct[BUFFER_SIZE];

    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (zap->clients[i].fd != cl->fd &&
            zap->clients[i].fd != -1 &&
            strcmp(zap->clients[i].team, "graphic") == 0) {
            snprintf(send_pgt, BUFFER_SIZE,"pgt %d %d\n", cl->fd, ressource);
            snprintf(send_bct, BUFFER_SIZE,"bct %d %d %d %d %d %d %d %d %d\n",
                cl->posX, cl->posY, zap->map->tile[cl->posY][cl->posX].food,
                zap->map->tile[cl->posY][cl->posX].linemate,
                zap->map->tile[cl->posY][cl->posX].deraumere,
                zap->map->tile[cl->posY][cl->posX].sibur,
                zap->map->tile[cl->posY][cl->posX].mendiane,
                zap->map->tile[cl->posY][cl->posX].phiras,
                zap->map->tile[cl->posY][cl->posX].thystame);
            send_response(zap->clients[i].fd, send_bct);
            send_response(zap->clients[i].fd, send_pgt);
        }
    }
}
