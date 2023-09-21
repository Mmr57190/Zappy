/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** broadcast3
*/

#include "../../include/server.h"

int *calcul_p6(client_t *cl)
{
    int *p6 = malloc(sizeof(int) * 2);

    if (cl->orientation == 'N') {
        p6[0] = cl->posY + 1;
        p6[1] = cl->posX + 1;
    }
    if (cl->orientation == 'S') {
        p6[0] = cl->posY - 1;
        p6[1] = cl->posX - 1;
    }
    if (cl->orientation == 'E') {
        p6[0] = cl->posY - 1;
        p6[1] = cl->posX + 1;
    }
    if (cl->orientation == 'O'){
        p6[0] = cl->posY + 1;
        p6[1] = cl->posX - 1;
    }
    return (p6);
}

int *calcul_p7(client_t *cl)
{
    int *p7 = malloc(sizeof(int) * 2);

    if (cl->orientation == 'N') {
        p7[0] = cl->posY;
        p7[1] = cl->posX + 1;
    }
    if (cl->orientation == 'S') {
        p7[0] = cl->posY;
        p7[1] = cl->posX - 1;
    }
    if (cl->orientation == 'E') {
        p7[0] = cl->posY - 1;
        p7[1] = cl->posX;
    }
    if (cl->orientation == 'O'){
        p7[0] = cl->posY + 1;
        p7[1] = cl->posX;
    }
    return (p7);
}

int *calcul_p8(client_t *cl)
{
    int *p8 = malloc(sizeof(int) * 2);

    if (cl->orientation == 'N') {
        p8[0] = cl->posY - 1;
        p8[1] = cl->posX + 1;
    }
    if (cl->orientation == 'S') {
        p8[0] = cl->posY + 1;
        p8[1] = cl->posX - 1;
    }
    if (cl->orientation == 'E') {
        p8[0] = cl->posY + 1;
        p8[1] = cl->posX + 1;
    }
    if (cl->orientation == 'O'){
        p8[0] = cl->posY - 1;
        p8[1] = cl->posX - 1;
    }
    return (p8);
}
