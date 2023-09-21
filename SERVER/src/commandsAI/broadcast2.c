/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** broadcast2
*/

#include "../../include/server.h"

int *calcul_p1(client_t *cl)
{
    int *p1 = malloc(sizeof(int) * 2);

    if (cl->orientation == 'N') {
        p1[0] = cl->posY - 1;
        p1[1] = cl->posX;
    }
    if (cl->orientation == 'S') {
        p1[0] = cl->posY + 1;
        p1[1] = cl->posX;
    }
    if (cl->orientation == 'E') {
        p1[0] = cl->posY;
        p1[1] = cl->posX + 1;
    }
    if (cl->orientation == 'O') {
        p1[0] = cl->posY;
        p1[1] = cl->posX - 1;
    }
    return (p1);
}

int *calcul_p2(client_t *cl)
{
    int *p2 = malloc(sizeof(int) * 2);

    if (cl->orientation == 'N') {
        p2[0] = cl->posY - 1;
        p2[1] = cl->posX - 1;
    }
    if (cl->orientation == 'S') {
        p2[0] = cl->posY + 1;
        p2[1] = cl->posX + 1;
    }
    if (cl->orientation == 'E') {
        p2[0] = cl->posY - 1;
        p2[1] = cl->posX + 1;
    }
    if (cl->orientation == 'O'){
        p2[0] = cl->posY + 1;
        p2[1] = cl->posX - 1;
    }
    return (p2);
}

int *calcul_p3(client_t *cl)
{
    int *p3 = malloc(sizeof(int) * 2);

    if (cl->orientation == 'N') {
        p3[0] = cl->posY;
        p3[1] = cl->posX - 1;
    }
    if (cl->orientation == 'S') {
        p3[0] = cl->posY;
        p3[1] = cl->posX + 1;
    }
    if (cl->orientation == 'E') {
        p3[0] = cl->posY + 1;
        p3[1] = cl->posX;
    }
    if (cl->orientation == 'O'){
        p3[0] = cl->posY - 1;
        p3[1] = cl->posX;
    }
    return (p3);
}

int *calcul_p4(client_t *cl)
{
    int *p4 = malloc(sizeof(int) * 2);

    if (cl->orientation == 'N') {
        p4[0] = cl->posY + 1;
        p4[1] = cl->posX - 1;
    }
    if (cl->orientation == 'S') {
        p4[0] = cl->posY - 1;
        p4[1] = cl->posX + 1;
    }
    if (cl->orientation == 'E') {
        p4[0] = cl->posY - 1;
        p4[1] = cl->posX - 1;
    }
    if (cl->orientation == 'O'){
        p4[0] = cl->posY + 1;
        p4[1] = cl->posX + 1;
    }
    return (p4);
}

int *calcul_p5(client_t *cl)
{
    int *p5 = malloc(sizeof(int) * 2);

    if (cl->orientation == 'N') {
        p5[0] = cl->posY + 1;
        p5[1] = cl->posX;
    }
    if (cl->orientation == 'S') {
        p5[0] = cl->posY - 1;
        p5[1] = cl->posX;
    }
    if (cl->orientation == 'E') {
        p5[0] = cl->posY;
        p5[1] = cl->posX - 1;
    }
    if (cl->orientation == 'O'){
        p5[0] = cl->posY;
        p5[1] = cl->posX + 1;
    }
    return (p5);
}
