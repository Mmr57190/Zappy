/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** forward2
*/

#include "../../include/server.h"

void forward_n(client_t *cl, zappy_t *zap)
{
    zap->map->tile[cl->posY][cl->posX].players--;
    if (cl->posY - 1 == -1) {
        cl->posY = zap->map->y - 1;
        zap->map->tile[cl->posY][cl->posX].players++;
    } else {
        cl->posY -= 1;
        zap->map->tile[cl->posY][cl->posX].players++;
    }
}

void forward_s(client_t *cl, zappy_t *zap)
{
    zap->map->tile[cl->posY][cl->posX].players--;
    if (cl->posY + 1 == zap->map->y) {
        cl->posY = 0;
        zap->map->tile[cl->posY][cl->posX].players++;
    } else {
        cl->posY += 1;
        zap->map->tile[cl->posY][cl->posX].players++;
    }
}

void forward_o(client_t *cl, zappy_t *zap)
{
    zap->map->tile[cl->posY][cl->posX].players--;
    if (cl->posX - 1 == -1) {
        cl->posX = zap->map->x - 1;
        zap->map->tile[cl->posY][cl->posX].players++;
    } else {
        cl->posX -= 1;
        zap->map->tile[cl->posY][cl->posX].players++;
    }
}

void forward_e(client_t *cl, zappy_t *zap)
{
    zap->map->tile[cl->posY][cl->posX].players--;
    if (cl->posX + 1 == zap->map->x) {
        cl->posX = 0;
        zap->map->tile[cl->posY][cl->posX].players++;
    } else {
        cl->posX += 1;
        zap->map->tile[cl->posY][cl->posX].players++;
    }
}
