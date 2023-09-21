/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCY-4-1-myftp-lefeuvre.aristide
** File description:
** utils
*/

#include "../include/server.h"

void create_server_socket_2(int s_fd, struct sockaddr_in s_addr)
{
    if (bind(s_fd, (struct sockaddr *)&s_addr, sizeof(s_addr)) == -1) {
        printf("Error binding socket\n");
        exit(EXIT_FAILURE);
    }
    if (listen(s_fd, 10) == -1) {
        printf("Error listening socket\n");
        exit(EXIT_FAILURE);
    }
}

int create_server_socket(int port)
{
    int s_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (s_fd == -1) {
        printf("Error creating socket\n");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in s_addr;
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(port);
    s_addr.sin_addr.s_addr = INADDR_ANY;
    int opt = 1;
    if (setsockopt(s_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error setting socket options\n");
        exit(EXIT_FAILURE);
    }
    create_server_socket_2(s_fd, s_addr);
    return s_fd;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

void check_select(client_t *cl, fd_set rfds, struct timeval tv)
{
    select(cl->fd + 1, &rfds, NULL, NULL, &tv);
}

void check_max_fd(client_t *clients)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].fd != -1) {
            fd_set rfds;
            FD_ZERO(&rfds);
            FD_SET(clients[i].fd, &rfds);
            struct timeval tv;
            tv.tv_sec = 0;
            tv.tv_usec = 0;
            check_select(clients, rfds, tv);
        }
    }
}
