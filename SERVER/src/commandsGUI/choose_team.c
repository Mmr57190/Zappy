/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** choose_team
*/

#include "../../include/server.h"

static int choose_team2(zappy_t *zap, client_t *cl, char *message, int i)
{
    if (strcmp(message, zap->teams[i].name) == 0)
        if (zap->teams[i].nbClients <= zap->teams[i].nbMax) {
            cl->team = malloc(sizeof(char) * strlen(zap->teams[i].name) + 1);
            cl->team = strcpy(cl->team, zap->teams[i].name);
            zap->teams[i].nbClients++;
            cl->nbCommands = 0;
            char buffer[BUFFER_SIZE];
            snprintf(buffer, BUFFER_SIZE,"%d\n%d %d\n", \
            (zap->teams[i].nbMax - zap->teams[i].nbClients), \
            zap->map->x, zap->map->y);
            send_response(cl->fd, buffer);
            pnw(zap, cl);
            cl->cmd = NULL;
            return 1;
        }
    return 0;
}

void choose_team(zappy_t *zap, client_t *cl, char *message)
{
    for (int i = 0; i < zap->nbTeams; i++) {
        if (choose_team2(zap, cl, message, i) == 1)
            return;
    }
    send_response(cl->fd, "ko\n");
}
