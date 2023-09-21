/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** utils_2
*/

#include "../include/server.h"

void send_response(int client_fd, char *response)
{
    int err = 0;

    err = fcntl(client_fd, F_GETFL);
    if (err == -1) {
        perror("fcntl");
        return;
    }
    if (send(client_fd, response, strlen(response), MSG_NOSIGNAL) == -1) {
        return;
    }
}

void check_client(zappy_t *zap, client_t *clients, fd_set readfs)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].fd != -1) {
            clients[i].cycle++;
            if (eat_food(zap, &readfs, &clients[i]) == 0)
                handle_client(zap, &clients[i], &readfs);
        }
    }
}

void rm_client_team_2(zappy_t *zap, client_t *cl)
{
    for (int i = 0; i < zap->nbTeams; i++)
        if (cl->team != NULL &&
        strcmp(cl->team, zap->teams[i].name) == 0) {
            zap->teams[i].nbClients--;
            break;
        }
}

static void rm_client_suit(zappy_t *zap, client_t *cl)
{
    cl->nbCommands = 1;
    cl->deraumere = 0;
    cl->food = 0;
    cl->linemate = 0;
    cl->mendiane = 0;
    cl->phiras = 0;
    cl->sibur = 0;
    cl->thystame = 0;
    cl->posX = 0;
    cl->posY = 0;
    cl->orientation = 'N';
    cl->level = 1;
    cl->tick = 0;
}

void rm_client_team(zappy_t *zap, client_t *cl)
{
    printf("Client %d died\n", cl->fd);
    printf("client team : %s\n", cl->team);
    printf("%d\n", zap->nbClients);
    if (strcmp(cl->team, "NULL") != 0) {
        rm_client_team_2(zap, cl);
    }
    free(cl->team);
    zap->map->tile[cl->posY][cl->posX].players--;
    zap->nbClients--;
    if (cl->buffer != NULL)
        for (int i = 0; i < 9; i++)
            free(cl->buffer[i]);
    free(cl->buffer);
    free(cl->whoElevate);
    free(cl->cmd);
    rm_client_suit(zap, cl);
}
