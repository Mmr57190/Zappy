/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** utils3
*/

#include "../include/server.h"

void send_first(client_t *clients, int client_fd, zappy_t *zap)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].fd == -1) {
            init_clients(&clients[i], client_fd, zap);
            send_response(client_fd, "WELCOME\n");
            return;
        }
    }
}

bool checknewclient(int server_fd,client_t *clients,fd_set readfs,
zappy_t *zap)
{
    if (FD_ISSET(server_fd, &readfs)) {
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd == -1) {
            return false;
        }
        send_first(clients, client_fd, zap);
    }
    return true;
}

int findmin2(float *d)
{
    if (d[4] < d[0] && d[4] < d[1] && d[4] < d[2] && d[4] < d[3] &&
    d[4] < d[5] && d[4] < d[6] && d[4] < d[7])
        return 5;
    if (d[5] < d[0] && d[5] < d[1] && d[5] < d[2] && d[5] < d[3] &&
    d[5] < d[4] && d[5] < d[6] && d[5] < d[7])
        return 6;
    if (d[6] < d[0] && d[6] < d[1] && d[6] < d[2] && d[6] < d[3] &&
    d[6] < d[4] && d[6] < d[5] && d[6] < d[7])
        return 7;
    if (d[7] < d[0] && d[7] < d[1] && d[7] < d[2] && d[7] < d[3] &&
    d[7] < d[4] && d[7] < d[5] && d[7] < d[6])
        return 8;
    return 0;
}

int findmin(float *d)
{
    if (d[0] < d[1] && d[0] < d[2] && d[0] < d[3] && d[0] < d[4] &&
    d[0] < d[5] && d[0] < d[6] && d[0] < d[7])
        return 1;
    if (d[1] < d[0] && d[1] < d[2] && d[1] < d[3] && d[1] < d[4] &&
    d[1] < d[5] && d[1] < d[6] && d[1] < d[7])
        return 2;
    if (d[2] < d[0] && d[2] < d[1] && d[2] < d[3] && d[2] < d[4] &&
    d[2] < d[5] && d[2] < d[6] && d[2] < d[7])
        return 3;
    if (d[3] < d[0] && d[3] < d[1] && d[3] < d[2] && d[3] < d[4] &&
    d[3] < d[5] && d[3] < d[6] && d[3] < d[7])
        return 4;
    return (findmin2(d));
}

void check_snprintf(int err, client_t *cl, char *msg)
{
    if (err == -1)
        send_response(cl->fd, "ko\n");
    else
        send_response(cl->fd, msg);
}
