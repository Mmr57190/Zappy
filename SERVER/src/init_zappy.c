/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** init_zappy
*/

#include "../include/server.h"

void init_density(int x, int y)
{
    food_count = (x * y) * 0.5;
    linemate_count = (x * y) * 0.3;
    deraumere_count = (x * y) * 0.15;
    sibur_count = (x * y) * 0.1;
    mendiane_count = (x * y) * 0.1;
    phiras_count = (x * y) * 0.08;
    thystame_count = (x * y) * 0.05;
}

static void init_tile(tile_t *tile, int x, int y)
{
    tile->food = 0;
    tile->linemate = 0;
    tile->deraumere = 0;
    tile->sibur = 0;
    tile->mendiane = 0;
    tile->phiras = 0;
    tile->thystame = 0;
    tile->players = 0;
}

static void init_map(zappy_t *zappy, server_parameter *params)
{
    int x = params->width;
    int y = params->height;
    int i = 0;

    zappy->map = malloc(sizeof(map_t));
    zappy->map->x = x;
    zappy->map->y = y;
    init_density(x, y);
    zappy->map->tile = malloc(sizeof(tile_t*) * y);
    for (; i < y; i++) {
        zappy->map->tile[i] = malloc(sizeof(tile_t) * x);
        for (int j = 0; j < x; j++)
            init_tile(&zappy->map->tile[i][j] , j, i);
    }
    while (food_count != 0 || linemate_count != 0 || deraumere_count != 0 ||
    sibur_count != 0 || mendiane_count != 0 || phiras_count != 0 ||
    thystame_count != 0)
        fill_map(zappy, x, y, 0);
}

void init_zappy2(zappy_t *zappy, server_parameter *params)
{
    zappy->nbTeams = params->nbTeams;
    zappy->clients = malloc(sizeof(client_t) * MAX_CLIENTS);
    for (int i = 0; i < MAX_CLIENTS; i++)
        zappy->clients[i].fd = -1;
    zappy->nbClients = 0;
    zappy->freq = params->freq;
    zappy->tick = 0;
    zappy->cmdTime = malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++)
        zappy->cmdTime[i] = -1;
    zappy->cmd = malloc(sizeof(char*) * 10);
    for (int i = 0; i < 10; i++)
        zappy->cmd[i] = NULL;
    init_map(zappy, params);
}

void init_zappy(zappy_t *zappy, server_parameter *params)
{
    int j = 0;

    zappy->teams = malloc(sizeof(team_t) * params->nbTeams);
    for (int i = 0; i < params->nbTeams; i++) {
        zappy->teams[i].name = malloc(sizeof(char) * strlen(params->teams[i]) + 1);
        zappy->teams[i].name = strcpy(zappy->teams[i].name, params->teams[i]);
        zappy->teams[i].nbMax = params->clientsNb;
        zappy->teams[i].nbClients = 0;
    }
    init_zappy2(zappy, params);
}
