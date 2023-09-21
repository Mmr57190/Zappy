/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** set2
*/

#include "../../include/server.h"

void set_deraumere(zappy_t *zap, client_t *cl, char *response)
{
    if (cl->deraumere > 0) {
        zap->map->tile[cl->posY][cl->posX].deraumere++;
        cl->deraumere--;
        send_response(cl->fd, "ok\n");
    } else
        send_response(cl->fd, "ko\n");
}

void set_sibur(zappy_t *zap, client_t *cl, char *response)
{
    if (cl->sibur > 0) {
        zap->map->tile[cl->posY][cl->posX].sibur++;
        cl->sibur--;
        send_response(cl->fd, "ok\n");
    } else
        send_response(cl->fd, "ko\n");
}

void set_mendiane(zappy_t *zap, client_t *cl, char *response)
{
    if (cl->mendiane > 0) {
        zap->map->tile[cl->posY][cl->posX].mendiane++;
        cl->mendiane--;
        send_response(cl->fd, "ok\n");
    } else
        send_response(cl->fd, "ko\n");
}

void set_phiras(zappy_t *zap, client_t *cl, char *response)
{
    if (cl->phiras > 0) {
        zap->map->tile[cl->posY][cl->posX].phiras++;
        cl->phiras--;
        send_response(cl->fd, "ok\n");
    } else
        send_response(cl->fd, "ko\n");
}

void set_thystame(zappy_t *zap, client_t *cl, char *response)
{
    if (cl->thystame > 0) {
        zap->map->tile[cl->posY][cl->posX].thystame++;
        cl->thystame--;
        send_response(cl->fd, "ok\n");
    } else
        send_response(cl->fd, "ko\n");
}
