/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** incantation2
*/

#include "../../include/server.h"

void first_incantation_level_1(zappy_t *zap, client_t *cl)
{
    if (zap->map->tile[cl->posY][cl->posX].linemate >= 1) {
        send_response(cl->fd, "Elevation underway\n");
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (zap->clients[i].fd != -1 &&
            strcmp(zap->clients[i].team, "graphic") == 0) {
                char to_send[BUFFER_SIZE];
                int r = fcntl(zap->clients[i].fd, F_GETFL);
                if (r == -1)
                    break;
                snprintf(to_send, BUFFER_SIZE,"pic %d %d %d %d\n",
                cl->posX, cl->posY, (cl->level + 1), cl->fd);
                send_response(zap->clients[i].fd, to_send);
            }
        }
    } else {
        cl->cmd = NULL;
        send_response(cl->fd, "ko\n");
    }
}

void first_incantation_level_2(zappy_t *zap, client_t *cl, client_t *cl2)
{
    int l = 0;

    if (zap->map->tile[cl->posY][cl->posX].linemate >= 2 &&
    zap->map->tile[cl->posY][cl->posX].deraumere >= 2 &&
    zap->map->tile[cl->posY][cl->posX].sibur >= 2) {
        cl->buffer = NULL;
        cl2->buffer = NULL;
        cl2->cycle = cl->cycle;
        cl2->cmd = strdup("Incantation\n");
        cl->whoElevate[0] = cl->fd;
        cl->whoElevate[1] = cl2->fd;
        cl2->whoElevate[0] = cl2->fd;
        cl2->whoElevate[1] = cl->fd;
        send_response(cl->fd, "Elevation underway\n");
        send_response(cl2->fd, "Elevation underway\n");
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (zap->clients[i].fd != -1 &&
            strcmp(zap->clients[i].team, "graphic") == 0) {
                char to_send[BUFFER_SIZE];
                int r = fcntl(zap->clients[i].fd, F_GETFL);
                if (r == -1)
                    break;
                snprintf(to_send, BUFFER_SIZE,"pic %d %d %d %d %d\n",
                cl->posX, cl->posY, (cl->level + 1), cl->fd, cl2->fd);
                send_response(zap->clients[i].fd, to_send);
            }
        }
    } else {
        cl->cmd = NULL;
        for (int i = 0; i < 10; i++)
            cl->buffer[i] = NULL;
        send_response(cl->fd, "ko\n");
    }
}

void first_incantation_level_3(zappy_t *zap, client_t *cl, client_t *cl2)
{
    int l = 0;

    if (zap->map->tile[cl->posY][cl->posX].linemate >= 4 &&
    zap->map->tile[cl->posY][cl->posX].sibur >= 2 &&
    zap->map->tile[cl->posY][cl->posX].phiras >= 4) {
        cl->buffer = NULL;
        cl2->buffer = NULL;
        cl2->cmd = strdup("Incantation\n");
        cl2->cycle = cl->cycle;
        cl->whoElevate[0] = cl->fd;
        cl->whoElevate[1] = cl2->fd;
        cl2->whoElevate[0] = cl2->fd;
        cl2->whoElevate[1] = cl->fd;
        send_response(cl2->fd, "Elevation underway\n");
        send_response(cl->fd, "Elevation underway\n");
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (zap->clients[i].fd != -1 &&
            strcmp(zap->clients[i].team, "graphic") == 0) {
                char to_send[BUFFER_SIZE];
                int r = fcntl(zap->clients[i].fd, F_GETFL);
                if (r == -1)
                    break;
                snprintf(to_send, BUFFER_SIZE,"pic %d %d %d %d %d\n",
                cl->posX, cl->posY, (cl->level + 1), cl->fd, cl2->fd);
                send_response(zap->clients[i].fd, to_send);
            }
        }
    } else {
        cl->cmd = NULL;
        send_response(cl->fd, "ko\n");
    }
}

void first_incantation_level_4(zappy_t *zap, client_t *cl, client_t **tmp)
{
    int l = 0;

    if (zap->map->tile[cl->posY][cl->posX].linemate >= 4 &&
    zap->map->tile[cl->posY][cl->posX].deraumere >= 4 &&
    zap->map->tile[cl->posY][cl->posX].sibur >= 8 &&
    zap->map->tile[cl->posY][cl->posX].phiras >= 4) {
        cl->buffer = NULL;
        tmp[1]->buffer = NULL;
        tmp[2]->buffer = NULL;
        tmp[3]->buffer = NULL;
        tmp[1]->cmd = strdup("Incantation\n");
        tmp[2]->cmd = strdup("Incantation\n");
        tmp[3]->cmd = strdup("Incantation\n");
        tmp[1]->cycle = cl->cycle;
        tmp[2]->cycle = cl->cycle;
        tmp[3]->cycle = cl->cycle;
        cl->whoElevate[0] = cl->fd;
        cl->whoElevate[1] = tmp[1]->fd;
        cl->whoElevate[2] = tmp[2]->fd;
        cl->whoElevate[3] = tmp[3]->fd;
        tmp[1]->whoElevate[0] = tmp[1]->fd;
        tmp[1]->whoElevate[1] = cl->fd;
        tmp[1]->whoElevate[2] = tmp[2]->fd;
        tmp[1]->whoElevate[3] = tmp[3]->fd;
        tmp[2]->whoElevate[0] = tmp[2]->fd;
        tmp[2]->whoElevate[1] = cl->fd;
        tmp[2]->whoElevate[2] = tmp[1]->fd;
        tmp[2]->whoElevate[3] = tmp[3]->fd;
        tmp[3]->whoElevate[0] = tmp[3]->fd;
        tmp[3]->whoElevate[1] = cl->fd;
        tmp[3]->whoElevate[2] = tmp[1]->fd;
        tmp[3]->whoElevate[3] = tmp[2]->fd;
        send_response(tmp[1]->fd, "Elevation underway\n");
        send_response(tmp[2]->fd, "Elevation underway\n");
        send_response(tmp[3]->fd, "Elevation underway\n");
        send_response(cl->fd, "Elevation underway\n");
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (zap->clients[i].fd != -1 &&
            strcmp(zap->clients[i].team, "graphic") == 0) {
                char to_send[BUFFER_SIZE];
                int r = fcntl(zap->clients[i].fd, F_GETFL);
                if (r == -1)
                    break;
                snprintf(to_send, BUFFER_SIZE,"pic %d %d %d %d %d %d %d\n",
                cl->posX, cl->posY, (cl->level + 1), cl->fd, tmp[1]->fd,
                tmp[2]->fd, tmp[3]->fd);
                send_response(zap->clients[i].fd, to_send);
            }
        }
    } else {
        cl->cmd = NULL;
        send_response(cl->fd, "ko\n");
    }
}

void first_incantation_level_5(zappy_t *zap, client_t *cl, client_t **tmp)
{
    int l = 0;

    if (zap->map->tile[cl->posY][cl->posX].linemate >= 4 &&
    zap->map->tile[cl->posY][cl->posX].deraumere >= 8 &&
    zap->map->tile[cl->posY][cl->posX].sibur >= 4 &&
    zap->map->tile[cl->posY][cl->posX].mendiane >= 12) {
        cl->buffer = NULL;
        tmp[1]->buffer = NULL;
        tmp[2]->buffer = NULL;
        tmp[3]->buffer = NULL;
        tmp[1]->cmd = strdup("Incantation\n");
        tmp[2]->cmd = strdup("Incantation\n");
        tmp[3]->cmd = strdup("Incantation\n");
        tmp[1]->cycle = cl->cycle;
        tmp[2]->cycle = cl->cycle;
        tmp[3]->cycle = cl->cycle;
        cl->whoElevate[0] = cl->fd;
        cl->whoElevate[1] = tmp[1]->fd;
        cl->whoElevate[2] = tmp[2]->fd;
        cl->whoElevate[3] = tmp[3]->fd;
        tmp[1]->whoElevate[0] = tmp[1]->fd;
        tmp[1]->whoElevate[1] = cl->fd;
        tmp[1]->whoElevate[2] = tmp[2]->fd;
        tmp[1]->whoElevate[3] = tmp[3]->fd;
        tmp[2]->whoElevate[0] = tmp[2]->fd;
        tmp[2]->whoElevate[1] = cl->fd;
        tmp[2]->whoElevate[2] = tmp[1]->fd;
        tmp[2]->whoElevate[3] = tmp[3]->fd;
        tmp[3]->whoElevate[0] = tmp[3]->fd;
        tmp[3]->whoElevate[1] = cl->fd;
        tmp[3]->whoElevate[2] = tmp[1]->fd;
        tmp[3]->whoElevate[3] = tmp[2]->fd;
        send_response(tmp[1]->fd, "Elevation underway\n");
        send_response(tmp[2]->fd, "Elevation underway\n");
        send_response(tmp[3]->fd, "Elevation underway\n");
        send_response(cl->fd, "Elevation underway\n");
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (zap->clients[i].fd != -1 &&
            strcmp(zap->clients[i].team, "graphic") == 0) {
                char to_send[BUFFER_SIZE];
                int r = fcntl(zap->clients[i].fd, F_GETFL);
                if (r == -1)
                    break;
                snprintf(to_send, BUFFER_SIZE,"pic %d %d %d %d %d %d %d\n",
                cl->posX, cl->posY, (cl->level + 1), cl->fd, tmp[1]->fd,
                tmp[2]->fd, tmp[3]->fd);
                send_response(zap->clients[i].fd, to_send);
            }
        }
    } else {
        cl->cmd = NULL;
        send_response(cl->fd, "ko\n");
    }
}