/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** forward
*/

#include "../../include/server.h"

void check_orientation(client_t *cl, zappy_t *zap)
{
    switch (cl->orientation) {
        case 'N':
            forward_n(cl, zap);
            break;
        case 'S':
            forward_s(cl, zap);
            break;
        case 'O':
            forward_o(cl, zap);
            break;
        case 'E':
            forward_e(cl, zap);
            break;
    }
}

void forward(zappy_t *zap, client_t *cl, char *message)
{
    if (cl->cycle >= 7) {
        cl->cycle = 0;
        free(cl->cmd);
        cl->cmd = NULL;
    } else {
        if (cl->cycle == 0) {
            cl->cmd = malloc(sizeof(char) * 8);
            if (cl->cmd == NULL)
                return;
            cl->cmd = strcpy(cl->cmd, "Forward");
        }
        return;
    }
    check_orientation(cl, zap);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (zap->clients[i].fd != -1 &&
        strcmp(zap->clients[i].team, "graphic") == 0) {
            char to_send[BUFFER_SIZE];
            snprintf(to_send, BUFFER_SIZE,"ppo %d %d %d %c\n", cl->fd, cl->posX,
            cl->posY, cl->orientation);
            send_response(zap->clients[i].fd, to_send);
        }
    }
    send_response(cl->fd, "ok\n");
}
