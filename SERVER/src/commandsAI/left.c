/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** left
*/

#include "../../include/server.h"

static void write_to_graph(zappy_t *zap, client_t *cl)
{
    int err = 0;

    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (zap->clients[i].fd != -1 &&
        strcmp(zap->clients[i].team, "graphic") == 0) {
            char to_send[BUFFER_SIZE];
            err = sprintf(to_send, "ppo %d %d %d %c\n", cl->fd, cl->posX, cl->posY,
            cl->orientation);
            check_snprintf(err, &zap->clients[i], to_send);
        }
    }
}

void make_left(client_t *cl)
{
    switch (cl->orientation) {
        case 'N':
            cl->orientation = 'O';
        send_response(cl->fd, "ok\n");
            break;
        case 'O':
            cl->orientation = 'S';
        send_response(cl->fd, "ok\n");
            break;
        case 'S':
            cl->orientation = 'E';
        send_response(cl->fd, "ok\n");
            break;
        case 'E':
            cl->orientation = 'N';
        send_response(cl->fd, "ok\n");
            break;
    }
}

void left(zappy_t *zap, client_t *cl, char *message)
{
    if (cl->cycle >= 7) {
        cl->cycle = 0;
        free(cl->cmd);
        cl->cmd = NULL;
    } else {
        if (cl->cycle == 0) {
            cl->cmd = malloc(sizeof(char) * 5);
            if (cl->cmd == NULL)
                return;
            cl->cmd = strcpy(cl->cmd, "Left");
        }
        return;
    }
    make_left(cl);
    write_to_graph(zap, cl);
}
