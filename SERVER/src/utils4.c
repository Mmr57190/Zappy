/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** utils4
*/

#include "../include/server.h"

static void remake_density2(void)
{
    if (food_count < 0)
        food_count = 0;
    if (linemate_count < 0)
        linemate_count = 0;
    if (deraumere_count < 0)
        deraumere_count = 0;
    if (sibur_count < 0)
        sibur_count = 0;
    if (mendiane_count < 0)
        mendiane_count = 0;
    if (phiras_count < 0)
        phiras_count = 0;
    if (thystame_count < 0)
        thystame_count = 0;
}

void remake_density(int x, int y, zappy_t *zap)
{
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            food_count -= zap->map->tile[i][j].food;
            linemate_count -= zap->map->tile[i][j].linemate;
            deraumere_count -= zap->map->tile[i][j].deraumere;
            sibur_count -= zap->map->tile[i][j].sibur;
            mendiane_count -= zap->map->tile[i][j].mendiane;
            phiras_count -= zap->map->tile[i][j].phiras;
            thystame_count -= zap->map->tile[i][j].thystame;
        }
    }
    remake_density2();
}

void tick_incr(zappy_t *zap)
{
    zap->tick++;
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (zap->clients[i].fd != -1)
            zap->clients[i].tick++;
    }
}

void find_max(zappy_t *zap, int max_fd, fd_set read_fds)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (zap->clients[i].fd != -1) {
            FD_SET(zap->clients[i].fd, &read_fds);
            max_fd = max(max_fd, zap->clients[i].fd);
        }
    }
}

int strlen_tab(char **tab)
{
    int i = 0;
    for (; tab[i] != NULL; i++);
    return i;
}
