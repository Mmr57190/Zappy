/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** tna
*/

#include "../../include/server.h"

void tna(zappy_t *zappy, client_t *client, char *arg)
{
    char *teams = malloc(sizeof(char) * 1000);

    if (teams == NULL) return;
    teams[0] = '\0';
    for (int i = 0; i < zappy->nbTeams; i++) {
        if (strcmp("graphic", zappy->teams[i].name) != 0) {
            strcat(teams, "tna ");
            strcat(teams, zappy->teams[i].name);
            strcat(teams, "\n");
        }
    }
    send_response(client->fd, teams);
    free(teams);
}
