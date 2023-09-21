/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** incantation
*/

#include "../../include/server.h"

void incantation_level_1(zappy_t *zap, client_t *cl)
{
    if (zap->map->tile[cl->posY][cl->posX].linemate >= 1 && cl->level == 1) {
        cl->level = 2;
        zap->map->tile[cl->posY][cl->posX].linemate--;
        send_response(cl->fd, "Current level: 2\n");
        plv_tograph(zap, cl);
        pie_tograph(zap, cl, 0);
    } else {
        send_response(cl->fd, "ko\n");
        pie_tograph(zap, cl, 1);
    }
}

void incantation_level_2(zappy_t *zap, client_t *cl)
{
    int j = 0;
    int err = 0;
    client_t *cl2 = NULL;

    if (zap->map->tile[cl->posY][cl->posX].linemate >= 2 &&
    zap->map->tile[cl->posY][cl->posX].deraumere >= 2 &&
    zap->map->tile[cl->posY][cl->posX].sibur >= 2) {
        if (zap->map->tile[cl->posY][cl->posX].players >= 2 &&
        cl->level == 2) {
            zap->map->tile[cl->posY][cl->posX].linemate -= 2;
            zap->map->tile[cl->posY][cl->posX].deraumere -= 2;
            zap->map->tile[cl->posY][cl->posX].sibur -= 2;
            cl = get_client(zap, cl->fd, 3, "Current level: 3\n");
            cl2 = get_client(zap, cl->whoElevate[1], 3, "Current level: 3\n");
            plv_tograph(zap, cl);
            plv_tograph(zap, cl2);
            pie_tograph(zap, cl, 0);
        }
    } else {
        send_response(cl->fd, "ko\n");
        pie_tograph(zap, cl, 1);
    }
}

void incantation_level_3(zappy_t *zap, client_t *cl)
{
    int j = 0;
    client_t *cl1 = NULL;

    if (zap->map->tile[cl->posY][cl->posX].linemate >= 4 &&
    zap->map->tile[cl->posY][cl->posX].sibur >= 2 &&
    zap->map->tile[cl->posY][cl->posX].phiras >= 4) {
        if (zap->map->tile[cl->posY][cl->posX].players >= 2 && cl->level == 3) {
            zap->map->tile[cl->posY][cl->posX].linemate -= 4;
            zap->map->tile[cl->posY][cl->posX].sibur -= 2;
            zap->map->tile[cl->posY][cl->posX].phiras -= 4;
            cl = get_client(zap, cl->fd, 4, "Current level: 4\n");
            cl1 = get_client(zap, cl->whoElevate[1], 4, "Current level: 4\n");
            plv_tograph(zap, cl);
            plv_tograph(zap, cl1);
            pie_tograph(zap, cl, 0);
        }
    } else {
        send_response(cl->fd, "ko\n");
        pie_tograph(zap, cl, 1);
    }
}

void incantation_level_4(zappy_t *zap, client_t *cl)
{
    int j = 0;
    client_t *cl1 = NULL;
    client_t *cl2 = NULL;
    client_t *cl3 = NULL;

    if (zap->map->tile[cl->posY][cl->posX].linemate >= 4 &&
    zap->map->tile[cl->posY][cl->posX].deraumere >= 4 &&
    zap->map->tile[cl->posY][cl->posX].sibur >= 8 &&
    zap->map->tile[cl->posY][cl->posX].phiras >= 4) {
        if (zap->map->tile[cl->posY][cl->posX].players >= 4 && cl->level == 4) {
            zap->map->tile[cl->posY][cl->posX].linemate -= 4;
            zap->map->tile[cl->posY][cl->posX].deraumere -= 4;
            zap->map->tile[cl->posY][cl->posX].sibur -= 8;
            zap->map->tile[cl->posY][cl->posX].phiras -= 4;
            cl = get_client(zap, cl->fd, 5, "Current level: 5\n");
            cl1 = get_client(zap, cl->whoElevate[1], 5, "Current level: 5\n");
            cl2 = get_client(zap, cl->whoElevate[2], 5, "Current level: 5\n");
            cl3 = get_client(zap, cl->whoElevate[3], 5, "Current level: 5\n");
            plv_tograph(zap, cl);
            plv_tograph(zap, cl1);
            plv_tograph(zap, cl2);
            plv_tograph(zap, cl3);
            pie_tograph(zap, cl, 0);
        }
    } else {
        send_response(cl->fd, "ko\n");
        pie_tograph(zap, cl, 1);
    }
}

void incantation_level_5(zappy_t *zap, client_t *cl)
{
    int j = 0;
    client_t *cl1 = NULL;
    client_t *cl2 = NULL;
    client_t *cl3 = NULL;
    client_t *cl4 = NULL;

    if (zap->map->tile[cl->posY][cl->posX].linemate >= 4 &&
    zap->map->tile[cl->posY][cl->posX].deraumere >= 8 &&
    zap->map->tile[cl->posY][cl->posX].sibur >= 4 &&
    zap->map->tile[cl->posY][cl->posX].mendiane >= 12) {
        if (zap->map->tile[cl->posY][cl->posX].players >= 4 && cl->level == 5) {
            zap->map->tile[cl->posY][cl->posX].linemate -= 4;
            zap->map->tile[cl->posY][cl->posX].deraumere -= 8;
            zap->map->tile[cl->posY][cl->posX].sibur -= 4;
            zap->map->tile[cl->posY][cl->posX].mendiane -= 12;
            cl = get_client(zap, cl->fd, 6, "Current level: 6\n");
            cl1 = get_client(zap, cl->whoElevate[1], 6, "Current level: 6\n");
            cl2 = get_client(zap, cl->whoElevate[2], 6, "Current level: 6\n");
            cl3 = get_client(zap, cl->whoElevate[3], 6, "Current level: 6\n");
            plv_tograph(zap, cl);
            plv_tograph(zap, cl1);
            plv_tograph(zap, cl2);
            plv_tograph(zap, cl3);
            pie_tograph(zap, cl, 0);
        }
    } else {
        pie_tograph(zap, cl, 1);
        send_response(cl->fd, "ko\n");
    }
}


void first_check_incantation(zappy_t *zap, client_t *cl)
{
    int k = 1;
    client_t **tmp = malloc(sizeof(client_t *) * 6);

    if (cl->level == 1) {
        first_incantation_level_1(zap, cl);
        return;
    } else if (cl->level == 2 || cl->level == 3) {
        for (int i = 0; i < zap->nbClients; i++) {
            if (zap->clients[i].fd != cl->fd && zap->clients[i].posX == cl->posX &&
            zap->clients[i].posY == cl->posY && zap->clients[i].level == cl->level)
                switch (cl->level) {
                    case 2:
                        first_incantation_level_2(zap, cl, &zap->clients[i]);
                        return;
                    case 3:
                        first_incantation_level_3(zap, cl, &zap->clients[i]);
                        return;
                    default:
                }
        }
    } else if (cl->level == 4) {
        tmp[0] = cl;
        for (int i = 0; i < zap->nbClients; i++) {
            if (zap->clients[i].fd != cl->fd && zap->clients[i].posX == cl->posX &&
            zap->clients[i].posY == cl->posY && zap->clients[i].level == cl->level)
                switch (cl->level) {
                    case 4:
                        tmp[k] = &zap->clients[i];
                        k++;
                        if (k == 4) {
                            first_incantation_level_4(zap, cl, tmp);
                            return;
                        }
                    default:
                }
        }
    } else if (cl->level == 5) {
        tmp[0] = cl;
        for (int i = 0; i < zap->nbClients; i++) {
            if (zap->clients[i].fd != cl->fd && zap->clients[i].posX == cl->posX &&
            zap->clients[i].posY == cl->posY && zap->clients[i].level == cl->level)
                switch (cl->level) {
                    case 5:
                        tmp[k] = &zap->clients[i];
                        k++;
                        if (k == 4) {
                            first_incantation_level_5(zap, cl, tmp);
                            return;
                        }
                    default:
                }
        }
    }
    send_response(cl->fd, "ko\n");
    cl->cycle = 300;
    free(tmp);
}

void incantation(zappy_t *zap, client_t *cl, char *arg)
{
    if (cl->cycle >= 300) {
        cl->cycle = 0;
        free(cl->cmd);
        cl->cmd = NULL;
    } else {
        if (cl->cycle == 0) {
            cl->cmd = malloc(sizeof(char) * 13);
            if (cl->cmd == NULL)
                return;
            cl->cmd = strcpy(cl->cmd, "Incantation");
            first_check_incantation(zap, cl);
        }
        return;
    }
    switch (cl->level) {
        case 1:
            incantation_level_1(zap, cl);
            break;
        case 2:
            incantation_level_2(zap, cl);
            break;
        case 3:
            incantation_level_3(zap, cl);
            break;
        case 4:
            incantation_level_4(zap, cl);
            break;
        case 5:
            incantation_level_5(zap, cl);
            break;
        default:
    }
}
