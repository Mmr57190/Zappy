/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** take2
*/

#include "../../include/server.h"

void take_deraumere(zappy_t *zap, client_t *cl, char *response)
{
    if (zap->map->tile[cl->posY][cl->posX].deraumere > 0) {
        zap->map->tile[cl->posY][cl->posX].deraumere--;
        cl->deraumere++;
        send_response(cl->fd, "ok\n");
        event_gui(zap, cl, 2);
    } else
        send_response(cl->fd, "ko\n");
}

void take_sibur(zappy_t *zap, client_t *cl, char *response)
{
    if (zap->map->tile[cl->posY][cl->posX].sibur > 0) {
        zap->map->tile[cl->posY][cl->posX].sibur--;
        cl->sibur++;
        send_response(cl->fd, "ok\n");
        event_gui(zap, cl, 3);
    } else
        send_response(cl->fd, "ko\n");
}

void take_mendiane(zappy_t *zap, client_t *cl, char *response)
{
    if (zap->map->tile[cl->posY][cl->posX].mendiane > 0) {
        zap->map->tile[cl->posY][cl->posX].mendiane--;
        cl->mendiane++;
        send_response(cl->fd, "ok\n");
        event_gui(zap, cl, 4);
    } else
        send_response(cl->fd, "ko\n");
}

void take_phiras(zappy_t *zap, client_t *cl, char *response)
{
    if (zap->map->tile[cl->posY][cl->posX].phiras > 0) {
        zap->map->tile[cl->posY][cl->posX].phiras--;
        cl->phiras++;
        send_response(cl->fd, "ok\n");
        event_gui(zap, cl, 5);
    } else
        send_response(cl->fd, "ko\n");
}

void take_thystame(zappy_t *zap, client_t *cl, char *response)
{
    if (zap->map->tile[cl->posY][cl->posX].thystame > 0) {
        zap->map->tile[cl->posY][cl->posX].thystame--;
        cl->thystame++;
        send_response(cl->fd, "ok\n");
        event_gui(zap, cl, 6);
    } else
        send_response(cl->fd, "ko\n");
}
