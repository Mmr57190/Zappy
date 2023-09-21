/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCY-4-1-myteams-flavien.maameri
** File description:
** commands
*/

#pragma once
#include "./server.h"
#include <stdio.h>
#include <stdlib.h>

void bct(zappy_t *zap, client_t *cl, char *position);
void msz(zappy_t *zappy, client_t *client, char *arg);
void ppo(zappy_t *zappy, client_t *client, char *arg);
void plv(zappy_t *zap, client_t *client, char *arg);
void tna(zappy_t *zappy, client_t *client, char *arg);
void pin(zappy_t *zappy, client_t *client, char *arg);

void forward(zappy_t *zap, client_t *cl, char *message);
void inventory(zappy_t *zap, client_t *cl, char *message);
void left(zappy_t *zap, client_t *cl, char *message);
void right(zappy_t *zap, client_t *cl, char *message);
void look(zappy_t *zap, client_t *cl, char *message);
void take(zappy_t *zap, client_t *cl, char *response);
void set(zappy_t *zap, client_t *cl, char *response);
void incantation(zappy_t *zap, client_t *cl, char *arg);
void broadcast(zappy_t *zap, client_t *cl, char *arg);

const struct commands {
    char *name;
    void (*ptr)(zappy_t *zap, client_t *cl, char *arg);
} commands;

const struct commands COMMANDS_AI[] = {
    {"Inventory", inventory},
    {"Left", left},
    {"Right", right},
    {"Forward", forward},
    {"Look", look},
    {"Take", take},
    {"Set", set},
    {"Incantation", incantation},
    {"Broadcast", broadcast},
    {NULL, NULL}
};

const struct commands COMMANDS_GRAPHIC[] = {
    {"pin", pin},
    {"tna", tna},
    {"plv", plv},
    {"ppo", ppo},
    {"msz", msz},
    {"bct", bct},
    {"mct", mct},
    {NULL, NULL}
};
