/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** Look
*/

#include "../../include/server.h"

void look_the_case(zappy_t *zap, client_t *cl, char **response, int X, int Y)
{
    for (int i = 0; i < zap->map->tile[Y][X].food; i++)
        *response = my_strcat(*response, "food ");
    for (int i = 0; i < zap->map->tile[Y][X].linemate; i++)
        *response = my_strcat(*response, "linemate ");
    for (int i = 0; i < zap->map->tile[Y][X].deraumere; i++)
        *response = my_strcat(*response, "deraumere ");
    for (int i = 0; i < zap->map->tile[Y][X].sibur; i++)
        *response = my_strcat(*response, "sibur ");
    for (int i = 0; i < zap->map->tile[Y][X].mendiane; i++)
        *response = my_strcat(*response, "mendiane ");
    for (int i = 0; i < zap->map->tile[Y][X].phiras; i++)
        *response = my_strcat(*response, "phiras ");
    for (int i = 0; i < zap->map->tile[Y][X].thystame; i++)
        *response = my_strcat(*response, "thystame ");
    for (int i = 0; i < zap->nbClients; i++)
        if (zap->clients[i].posX == X && zap->clients[i].posY == Y) {
            *response = my_strcat(*response, "player ");
        }
}

char *look_north(zappy_t *zap, client_t *cl, int nbTilesX, int nbTilesY, char *response)
{
    int reX = cl->posX;
    int reY = cl->posY;
    int X = cl->posX;
    int Y = cl->posY;

    response[0] = '\0';
    response = my_strcat(response, "[");
    for (int i = 0; i < nbTilesY; i++) {
        while (Y < 0 || Y > zap->map->y - 1)
            Y = cgpY(Y, i, zap);
        for (int j = 0; j < nbTilesX; j++) {
            X = reX + j;
            while (X < 0 || X > zap->map->x - 1)
                X = cgpX(X, i, zap);
            look_the_case(zap, cl, &response, X, Y);
            if (response[strlen(response) - 1] == ' ')
                response[strlen(response) - 1] = '\0';
            if (j != nbTilesX - 1)
                response = my_strcat(response, ",");
        }
        if (response[strlen(response) - 1] == ' ')
            response[strlen(response) - 1] = '\0';
        response = my_strcat(response, ",");
        nbTilesX += 2;
        reY--;
        Y = reY;
        reX--;
        X = reX;
    }
    response[strlen(response) - 1] = '\0';
    response = my_strcat(response, "]\n");
    return response;
}

char *look_east(zappy_t *zap, client_t *cl, int nbTilesX, int nbTilesY, char *response)
{
    int reX = cl->posX;
    int reY = cl->posY;
    int X = cl->posX;
    int Y = cl->posY;

    response[0] = '\0';
    response = my_strcat(response, "[");
    for (int i = 0; i < nbTilesY; i++) {
        while (X < 0 || X > zap->map->x - 1)
            X = cgpX(X, i, zap);
        for (int j = 0; j < nbTilesX; j++) {
            Y = reY + j;
            while (Y < 0 || Y > zap->map->y - 1)
                Y = cgpY(Y, i, zap);
            look_the_case(zap, cl, &response, X, Y);
            if (response[strlen(response) - 1] == ' ')
                response[strlen(response) - 1] = '\0';
            if (j != nbTilesX - 1)
                response = my_strcat(response, ",");
        }
        if (response[strlen(response) - 1] == ' ')
            response[strlen(response) - 1] = '\0';
        response = my_strcat(response, ",");
        nbTilesX += 2;
        reX++;
        X = reX;
        reY--;
        Y = reY;
    }
    response[strlen(response) - 1] = '\0';
    response = my_strcat(response, "]\n");
    return response;
}

char *look_south(zappy_t *zap, client_t *cl, int nbTilesX, int nbTilesY, char *response)
{
    int reX = cl->posX;
    int reY = cl->posY;
    int X = cl->posX;
    int Y = cl->posY;

    response[0] = '\0';
    response = my_strcat(response, "[");
    for (int i = 0; i < nbTilesY; i++) {
        while (Y < 0 || Y > zap->map->y - 1)
            Y = cgpY(Y, i, zap);
        for (int j = 0; j < nbTilesX; j++) {
            X = reX - j;
            while (X < 0 || X > zap->map->x - 1)
                X = cgpX(X, i, zap);
            look_the_case(zap, cl, &response, X, Y);
            if (response[strlen(response) - 1] == ' ')
                response[strlen(response) - 1] = '\0';
            if (j != nbTilesX - 1)
                response = my_strcat(response, ",");
        }
        if (response[strlen(response) - 1] == ' ')
            response[strlen(response) - 1] = '\0';
        response = my_strcat(response, ",");
        nbTilesX += 2;
        reY++;
        Y = reY;
        reX++;
        X = reX;
    }
    response[strlen(response) - 1] = '\0';
    response = my_strcat(response, "]\n");
    return response;
}

char *look_west(zappy_t *zap, client_t *cl, int nbTilesX, int nbTilesY, char *response)
{
    int reX = cl->posX;
    int reY = cl->posY;
    int X = cl->posX;
    int Y = cl->posY;

    response[0] = '\0';
    response = my_strcat(response, "[");
    for (int i = 0; i < nbTilesY; i++) {
        while (X < 0 || X > zap->map->x - 1)
            X = cgpX(X, i, zap);
        for (int j = 0; j < nbTilesX; j++) {
            Y = reY - j;
            while (Y < 0 || Y > zap->map->y - 1)
                Y = cgpY(Y, i, zap);
            look_the_case(zap, cl, &response, X, Y);
            if (response[strlen(response) - 1] == ' ')
                response[strlen(response) - 1] = '\0';
            if (j != nbTilesX - 1)
                response = my_strcat(response, ",");
        }
        if (response[strlen(response) - 1] == ' ')
            response[strlen(response) - 1] = '\0';
        response = my_strcat(response, ",");
        nbTilesX += 2;
        reX--;
        X = reX;
        reY++;
        Y = reY;
    }
    response[strlen(response) - 1] = '\0';
    response = my_strcat(response, "]\n");
    return response;
}

char *call_look(zappy_t *zap, client_t *cl, char *response)
{
    int nbTilesX = 1;
    int nbTilesY = 1;

    for (int i = 0; i < cl->level; i++)
        nbTilesY += 1;
    switch (cl->orientation) {
        case 'N':
            response = look_north(zap, cl, nbTilesX, nbTilesY, response);
            break;
        case 'S':
            response = look_south(zap, cl, nbTilesX, nbTilesY, response);
            break;
        case 'O':
            response = look_west(zap, cl, nbTilesX, nbTilesY, response);
            break;
        case 'E':
            response = look_east(zap, cl, nbTilesX, nbTilesY, response);
            break;
    }
    return response;
}

void look(zappy_t *zap, client_t *cl, char *message)
{
    int err = 0;

    if (cl->cycle >= 7) {
        cl->cycle = 0;
        free(cl->cmd);
        cl->cmd = NULL;
    } else {
        if (cl->cycle == 0) {
            cl->cmd = malloc(sizeof(char) * (strlen("Look") + 1));
            if (cl->cmd == NULL)
                return;
            cl->cmd = strcpy(cl->cmd, "Look");
        }
        return;
    }
    char *response = malloc(sizeof(char) * BUFFER_SIZE);
    if (response == NULL)
        return;
    response = call_look(zap, cl, response);
    check_snprintf(err, cl, response);
    free(response);
}
