/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCY-4-1-myftp-lefeuvre.aristide
** File description:
** server
*/

#include "../include/server.h"
#include <time.h>

static int quitting = 1;

static void quit(int sig)
{
    quitting = 0;
}

static void regenerate_ressources(zappy_t *zap)
{
    init_density(zap->map->x, zap->map->y);
    remake_density(zap->map->x, zap->map->y, zap);
    // print all food count
    // printf("%d %d %d %d %d %d %d\n", food_count, linemate_count,
    // deraumere_count, sibur_count, mendiane_count, phiras_count,
    // thystame_count);
    while (food_count != 0 || linemate_count != 0 ||
    deraumere_count != 0 || sibur_count != 0 ||
    mendiane_count != 0 || phiras_count != 0 ||
    thystame_count != 0)
        fill_map(zap, zap->map->x, zap->map->y, 1);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (zap->clients[i].fd != -1 &&
        strcmp(zap->clients[i].team, "graphic") == 0) {
            mct(zap, &zap->clients[i], NULL);
        }
    }
}

void run_server(int server_fd, zappy_t *zap)
{
    signal(SIGINT, quit);
    struct timeval tv;

    while (1) {
        tv.tv_sec = 0;
        tv.tv_usec = 1000000 / zap->freq;
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(server_fd, &read_fds);
        int max_fd = server_fd;
        for (int i = 0; i < zap->nbClients; i++) {
            if (zap->clients[i].fd != -1) {
                FD_SET(zap->clients[i].fd, &read_fds);
                max_fd = max(max_fd, zap->clients[i].fd);
            }
        }
        while (tv.tv_usec > 0) {
            int ret = select(max_fd + 1, &read_fds, NULL, NULL, &tv);
            if (ret == -1) {
                perror("select");
                return;
            }
        }
        tick_incr(zap);
        if (zap->tick % 20 == 0)
            regenerate_ressources(zap);
        check_max_fd(zap->clients);
        check_client(zap, zap->clients, read_fds);
        if (checknewclient(server_fd, zap->clients, read_fds, zap) == false)
            break;
    }
}

int main(int argc, char **argv)
{
    server_parameter *params;
    zappy_t *zappy;

    if (argc == 2 && (strcmp(argv[1], "-help") == 0 ||
    strcmp(argv[1], "-h") == 0))
        return (print_help());
    params = malloc(sizeof(server_parameter));
    init_params(params);
    if (check_args(params, argc, argv) == false) {
        clear_params(params, zappy);
        return 84;
    }
    zappy = malloc(sizeof(zappy_t));
    init_zappy(zappy, params);
    int server_fd = create_server_socket(params->port);
    run_server(server_fd, zappy);
    close(server_fd);
    clear_params(params, zappy);
    free_zappy(zappy);
    return 0;
}
