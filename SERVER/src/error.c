/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCY-4-1-myftp-lefeuvre.aristide
** File description:
** error
*/

#include "../include/server.h"

int food_count;
int linemate_count;
int deraumere_count;
int sibur_count;
int mendiane_count;
int phiras_count;
int thystame_count;

static bool params_error_2(server_parameter *params, int i)
{
    for (int j = 0; params->teams[j] != NULL; j++) {
        if (i != j && strcmp(params->teams[i], params->teams[j]) == 0) {
            printf("Error: team name already used\n");
            return false;
        }
    }
    return true;
}

static bool params_error(server_parameter *params)
{
    if (params->port == -1 || params->width == -1 || params->height == -1 ||
    params->clientsNb == -1 || params->teams[0] == NULL) {
        printf("Error: missing arguments\n");
        return false;
    }
    for (int i = 0; params->teams[i] != NULL; i++)
        if (params_error_2(params, i) == false)
            return false;
    return true;
}

static void fill_teams(server_parameter *params, int ac, char **av)
{
    int i = 0;
    char *str = "graphic";

    optind--;
    for (; optind < ac && *av[optind] != '-'; optind++, i++) {
        params->teams = realloc(params->teams, sizeof(char*) * (i + 2));
        params->teams[i] = strdup(av[optind]);
    }
    params->teams = realloc(params->teams, sizeof(char*) * (i + 2));
    params->teams[i] = strdup(str);
    params->teams[i + 1] = NULL;
    params->nbTeams = i + 1;
}

static void check_args_snd(server_parameter *params, int ac, char **av,\
int opt)
{
    int i = 0;

    switch (opt) {
        case 'c':
            params->clientsNb = atoi(optarg);
            break;
        case 'n':
            fill_teams(params, ac, av);
            break;
        case 'f':
            params->freq = atoi(optarg);
            break;
    }
}

bool check_args(server_parameter *params, int ac, char **av)
{
    int opt;
    int digit_optind = 0;

    while ((opt = getopt_long(ac, av, "p:x:y:c:n:f:",\
    longOpts, &digit_optind)) != -1) {
        switch (opt) {
            case 'p':
                params->port = atoi(optarg);
                break;
            case 'x':
                params->width = atoi(optarg);
                break;
            case 'y':
                params->height = atoi(optarg);
                break;
            default:
                check_args_snd(params, ac, av, opt);
        }
    }
    return params_error(params);
}
