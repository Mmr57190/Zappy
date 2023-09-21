/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCY-4-1-myftp-lefeuvre.aristide
** File description:
** init
*/

#include "../include/server.h"

static void init_clients2(client_t *cl, zappy_t *zap)
{
    cl->posX = rand() % zap->map->x;
    cl->posY = rand() % zap->map->y;
    zap->map->tile[cl->posY][cl->posX].players++;
    cl->level = 1;
    int ori = rand() % 4;
    if (ori == 0)
        cl->orientation = 'N';
    if (ori == 1)
        cl->orientation = 'S';
    if (ori == 2)
        cl->orientation = 'E';
    if (ori == 3)
        cl->orientation = 'O';
    cl->whoElevate = malloc(sizeof(int) * 6);
    for (int i = 0; i < 6; i++)
        cl->whoElevate[i] = -1;
    cl->whoElevate[0] = cl->fd;
}

void init_clients(client_t *cl, int client_fd, zappy_t *zap)
{
    zap->nbClients++;
    cl->fd = client_fd;
    cl->nbCommands = 1;
    cl->team = "NULL";
    cl->food = 10000000;
    cl->linemate = 0;
    cl->deraumere = 0;
    cl->sibur = 0;
    cl->mendiane = 0;
    cl->phiras = 0;
    cl->thystame = 0;
    cl->cycle = 0;
    cl->cmd = NULL;
    cl->buffer = NULL;
    cl->tick = 0;
    init_clients2(cl, zap);
}

void init_params(server_parameter *params)
{
    srand(time(NULL));
    params->port = -1;
    params->width = -1;
    params->height = -1;
    params->clientsNb = -1;
    params->freq = 100;
    params->teams = malloc(sizeof(char*) * 1);
    params->teams[0] = NULL;
}
