/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** Take
*/

#include "../../include/server.h"

void take_food(zappy_t *zap, client_t *cl, char *response)
{
    if (zap->map->tile[cl->posY][cl->posX].food > 0) {
        zap->map->tile[cl->posY][cl->posX].food--;
        cl->food++;
        send_response(cl->fd, "ok\n");
        event_gui(zap, cl, 0);
    } else
        send_response(cl->fd, "ko\n");
}

void take_linemate(zappy_t *zap, client_t *cl, char *response)
{
    if (zap->map->tile[cl->posY][cl->posX].linemate > 0) {
        zap->map->tile[cl->posY][cl->posX].linemate--;
        cl->linemate++;
        send_response(cl->fd, "ok\n");
        event_gui(zap, cl, 1);
    } else {
        send_response(cl->fd, "ko\n");
    }
}

int take3(zappy_t *zap, client_t *cl, char *response)
{
    if (strcmp(response, "linemate") == 0) {
        take_linemate(zap, cl, response);
        return 1;
    }
    if (strcmp(response, "deraumere") == 0) {
        take_deraumere(zap, cl, response);
        return 1;
    }
    if (strcmp(response, "thystame") == 0) {
        take_thystame(zap, cl, response);
        return 1;
    }
    return 0;
}

int take2(zappy_t *zap, client_t *cl, char *response)
{
    if (strcmp(response, "sibur") == 0) {
        take_sibur(zap, cl, response);
        return 1;
    }
    if (strcmp(response, "mendiane") == 0) {
        take_mendiane(zap, cl, response);
        return 1;
    }
    if (strcmp(response, "phiras") == 0) {
        take_phiras(zap, cl, response);
        return 1;
    }
    if (take3(zap, cl, response) == 1)
        return 1;
    return 0;
}

void take(zappy_t *zap, client_t *cl, char *response)
{
    if (cl->cycle >= 7) {
        cl->cycle = 0;
        free(cl->cmd);
        cl->cmd = NULL;
    } else {
        if (cl->cycle == 0) {
            cl->cmd = malloc(sizeof(char) * (strlen(response) + 6));
            if (cl->cmd == NULL)
                return;
            strcpy(cl->cmd, "Take ");
            strcat(cl->cmd, response);
        }
        return;
    }
    if (strcmp(response, "food") == 0) {
        take_food(zap, cl, response);
        return;
    }
    if (take2(zap, cl, response) == 0)
        send_response(cl->fd, "ko\n");
}
