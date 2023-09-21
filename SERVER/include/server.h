/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCY-4-1-myteams-flavien.maameri
** File description:
** server
*/

#pragma once

#ifndef _GNU_SOURCE
    #define _GNU_SOURCE 1
    #include <arpa/inet.h>
    #include <ctype.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/socket.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <unistd.h>
    #include <uuid/uuid.h>
    #include <getopt.h>
    #include <time.h>
    #include <math.h>
    #include <limits.h>
    #include <fcntl.h>

    #define BUFFER_SIZE 1024
    #define MAX_CLIENTS 1000

extern int food_count;
extern int linemate_count;
extern int deraumere_count;
extern int sibur_count;
extern int mendiane_count;
extern int phiras_count;
extern int thystame_count;

static const struct option longOpts[] = {
    { "p", required_argument, 0, 'p'},
    { "x", required_argument, 0, 'x'},
    { "y", required_argument, 0, 'y'},
    { "c", required_argument, 0, 'c'},
    { "f", required_argument, 0, 'f'},
    { "n", required_argument, 0, 'n'},
    {0, 0, 0, 0}
};

typedef struct {
    int fd;
    char *team;
    char *cmd;
    char **buffer;
    int posX;
    int posY;
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
    int nbCommands;
    char orientation;
    int level;
    int cycle;
    int tick;
    int *whoElevate;
} client_t;

typedef struct {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
    int players;
} tile_t;

typedef struct {
    int x;
    int y;
    tile_t **tile;
} map_t;

typedef struct {
    char *name;
    int nbMax;
    int nbClients;
} team_t;

typedef struct {
    team_t *teams;
    int nbTeams;
    map_t *map;
    client_t *clients;
    int nbClients;
    int freq;
    char **cmd;
    int *cmdTime;
    int tick;
} zappy_t;


typedef struct {
    int port;
    int width;
    int height;
    int clientsNb;
    int freq;
    char **teams;
    int nbTeams;
} server_parameter;

void send_response(int client_fd, char *response);

int create_server_socket(int port);

void init_clients(client_t *cl, int client_fd, zappy_t *zap);

void send_first(client_t *clients, int client_fd, zappy_t *zap);

bool checknewclient(int server_fd,client_t *clients,fd_set readfs,\
zappy_t *zap);

void check_client(zappy_t *zap, client_t *clients, fd_set readfs);

void clear_params(server_parameter *params, zappy_t *zap);

void init_params(server_parameter *params);

bool check_args(server_parameter *params, int ac, char **av);

void init_zappy(zappy_t *zappy, server_parameter *params);

void free_zappy(zappy_t *zappy);

void handle_client(zappy_t *zap, client_t *cl, fd_set *readfds);

void rm_client_team(zappy_t *zap, client_t *cl);

void pnw(zappy_t *zap, client_t *cl);

void pdi(zappy_t *zap, client_t *cl);

int get_time(zappy_t *zap);

void move_cmdtime(zappy_t *zap);

void less_cmdtime(zappy_t *zap);

int max(int a, int b);

void check_max_fd(client_t *clients);

int print_help(void);

void fill_map(zappy_t *zappy, int x, int y, int z);

void choose_team(zappy_t *zap, client_t *cl, char *message);

int *calcul_p1(client_t *cl);

int *calcul_p2(client_t *cl);

int *calcul_p3(client_t *cl);

int *calcul_p4(client_t *cl);

int *calcul_p5(client_t *cl);

int *calcul_p6(client_t *cl);

int *calcul_p7(client_t *cl);

int *calcul_p8(client_t *cl);

void freep(int **p1, int **p2, int **p3, int **p4);

void freep2(int **p5, int **p6, int **p7, int **p8);

int findmin(float *d);

void check_snprintf(int err, client_t *cl, char *msg);

void set_deraumere(zappy_t *zap, client_t *cl, char *response);

void set_sibur(zappy_t *zap, client_t *cl, char *response);

void set_mendiane(zappy_t *zap, client_t *cl, char *response);

void set_phiras(zappy_t *zap, client_t *cl, char *response);

void set_thystame(zappy_t *zap, client_t *cl, char *response);

void take_deraumere(zappy_t *zap, client_t *cl, char *response);

void take_sibur(zappy_t *zap, client_t *cl, char *response);

void take_mendiane(zappy_t *zap, client_t *cl, char *response);

void take_phiras(zappy_t *zap, client_t *cl, char *response);

void take_thystame(zappy_t *zap, client_t *cl, char *response);

void event_gui(zappy_t *zap, client_t *cl, int ressource);

void mct(zappy_t *zap, client_t *cl, char *position);

void init_density(int x, int y);

void first_incantation_level_1(zappy_t *zap, client_t *cl);

void first_incantation_level_2(zappy_t *zap, client_t *cl, client_t *cl2);

void first_incantation_level_3(zappy_t *zap, client_t *cl, client_t *cl2);

void remake_density(int x, int y, zappy_t *zap);

void forward_n(client_t *cl, zappy_t *zap);
void forward_s(client_t *cl, zappy_t *zap);
void forward_o(client_t *cl, zappy_t *zap);
void forward_e(client_t *cl, zappy_t *zap);

void event_gui(zappy_t *zap, client_t *cl, int ressource);

void tick_incr(zappy_t *zap);

void find_max(zappy_t *zap, int max_fd, fd_set read_fds);

int eat_food(zappy_t *zap, fd_set *readfds, client_t *cl);

void queue1(zappy_t *zap, client_t *cl, char *message);

void queue2(zappy_t *zap, client_t *cl, char *message);

void queue(zappy_t *zap, client_t *cl, char *message, int message_len);

int strlen_tab(char **tab);

void check_message(zappy_t *zap, client_t *cl, char *message, \
int message_len);

char *my_strcat(char *dest, char const *src);

int cgpX(int x, int etage, zappy_t *zap);

int cgpY(int y, int etage, zappy_t *zap);

void plv_tograph(zappy_t *zap, client_t *cl);

client_t *get_client(zappy_t *zap, int fd, int level, char *str);

void first_incantation_level_4(zappy_t *zap, client_t *cl, client_t **tmp);

void first_incantation_level_5(zappy_t *zap, client_t *cl, client_t **tmp);

void pie_tograph(zappy_t *zap, client_t *cl, int fd);

#endif
