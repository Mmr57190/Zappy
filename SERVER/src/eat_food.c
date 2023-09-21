/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** eat_food
*/

#include "../include/server.h"

int eat_food(zappy_t *zap, fd_set *readfds, client_t *cl)
{
    if (cl->tick >= 126 && cl->nbCommands != 1) {
        if (cl->food == 0) {
            printf("i will kill %d %s\n", cl->fd, cl->team);
            pdi(zap, cl);
            send_response(cl->fd, "dead\n");
            rm_client_team(zap, cl);
            close(cl->fd);
            FD_CLR(cl->fd, readfds);
            cl->fd = -1;
            return 1;
        }
        if (strcmp(cl->team, "graphic") != 0)
            cl->food--;
        cl->tick = 0;
    }
    return 0;
}
