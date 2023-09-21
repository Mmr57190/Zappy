/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** Set
*/

#include "../../include/server.h"

void set_food(zappy_t *zap, client_t *cl, char *response)
{
    if (cl->food > 0) {
        zap->map->tile[cl->posY][cl->posX].food++;
        cl->food--;
        send_response(cl->fd, "ok\n");
    } else
        send_response(cl->fd, "ko\n");
}

void set_linemate(zappy_t *zap, client_t *cl, char *response)
{
    if (cl->linemate > 0) {
        zap->map->tile[cl->posY][cl->posX].linemate++;
        cl->linemate--;
        send_response(cl->fd, "ok\n");
    } else
        send_response(cl->fd, "ko\n");
}

int set3(zappy_t *zap, client_t *cl, char *response)
{
    if (strcmp(response, "linemate") == 0) {
        set_linemate(zap, cl, response);
        return 1;
    }
    if (strcmp(response, "deraumere") == 0) {
        set_deraumere(zap, cl, response);
        return 1;
    }
    if (strcmp(response, "thystame") == 0) {
        set_thystame(zap, cl, response);
        return 1;
    }
    return 0;
}

int set2(zappy_t *zap, client_t *cl, char *response)
{
    if (strcmp(response, "sibur") == 0) {
        set_sibur(zap, cl, response);
        return 1;
    }
    if (strcmp(response, "mendiane") == 0) {
        set_mendiane(zap, cl, response);
        return 1;
    }
    if (strcmp(response, "phiras") == 0) {
        set_phiras(zap, cl, response);
        return 1;
    }
    if (set3(zap, cl, response) == 1)
        return 1;
    return 0;
}

void set(zappy_t *zap, client_t *cl, char *response)
{
    if (cl->cycle >= 7) {
        cl->cycle = 0;
        free(cl->cmd);
        cl->cmd = NULL;
    } else {
        if (cl->cycle == 0) {
            cl->cmd = malloc(sizeof(char) * (strlen(response) + 5));
            if (cl->cmd == NULL)
                return;
            strcpy(cl->cmd, "Set ");
            strcat(cl->cmd, response);
        }
        return;
    }
    if (strcmp(response, "food") == 0) {
        set_food(zap, cl, response);
        return;
    }
    if (set2(zap, cl, response) == 0)
        send_response(cl->fd, "ko\n");
}
