/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** fill_map
*/

#include "../include/server.h"

static void fill_map_3(zappy_t *zappy, int y, int x)
{
    for (int l = 0; l < sibur_count; l++) {
        zappy->map->tile[rand() % y][rand() % x].sibur++;
        sibur_count--;
    }
    for (int l = 0; l < mendiane_count; l++) {
        zappy->map->tile[rand() % y][rand() % x].mendiane++;
        mendiane_count--;
    }
    for (int l = 0; l < phiras_count; l++) {
        zappy->map->tile[rand() % y][rand() % x].phiras++;
        phiras_count--;
    }
    for (int l = 0; l < thystame_count; l++) {
        zappy->map->tile[rand() % y][rand() % x].thystame++;
        thystame_count--;
    }
}

static void fill_map_2(zappy_t *zappy, int z, int i)
{
    int x = zappy->map->x;
    int y = zappy->map->y;

    if (z == 0)
        for (int j = 0; j < x; j++)
            zappy->map->tile[i][j].players = 0;
    for (int l = 0; l < food_count; l++) {
        zappy->map->tile[rand() % y][rand() % x].food++;
        food_count--;
    }
    for (int l = 0; l < linemate_count; l++) {
        zappy->map->tile[rand() % y][rand() % x].linemate++;
        linemate_count--;
    }
    for (int l = 0; l < deraumere_count; l++) {
        zappy->map->tile[rand() % y][rand() % x].deraumere++;
        deraumere_count--;
    }
    fill_map_3(zappy, y, x);
}

void fill_map(zappy_t *zappy, int x, int y, int z)
{
    for (int i = 0; i < y; i++) {
        fill_map_2(zappy, z, i);
    }
}
