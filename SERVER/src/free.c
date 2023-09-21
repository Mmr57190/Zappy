/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** free
*/

#include "../include/server.h"

void free_zappy(zappy_t *zappy)
{
    for (int i = 0; i <= zappy->nbTeams - 1; i++) {
        free(zappy->teams[i].name);
    }
    for (int i = 0; i < zappy->map->y; i++)
        free(zappy->map->tile[i]);
    // for (int i = 0; i < MAX_CLIENTS; i++) {
    //     if (zappy->clients[i].fd != -1 && zappy->clients[i].team != NULL) {
    //         rm_client_team(zappy, &zappy->clients[i]);
    //     }
    // }
    free(zappy->cmdTime);
    free(zappy->cmd);
    free(zappy->clients);
    free(zappy->map->tile);
    free(zappy->map);
    free(zappy->teams);
    free(zappy);
}

void clear_params(server_parameter *params, zappy_t *zap)
{
    for (int i = 0; params->teams[i] != NULL; i++)
        free(params->teams[i]);
    free(params->teams);
    free(params);
}

void freep(int **p1, int **p2, int **p3, int **p4)
{
    free(*p1);
    free(*p2);
    free(*p3);
    free(*p4);
}

void freep2(int **p5, int **p6, int **p7, int **p8)
{
    free(*p5);
    free(*p6);
    free(*p7);
    free(*p8);
}
