/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** Broadcast
*/

#include "../../include/server.h"
#include <stdlib.h>

float min(float a, float b)
{
    if (a < b)
        return (a);
    return (b);
}

float calcul_dcycl(zappy_t *zap, client_t *clEm, int Y, int X)
{
    float dx = abs(clEm->posX - X);
    float dy = abs(clEm->posY - Y);
    dx = min(dx, zap->map->x - dx);
    dy = min(dy, zap->map->y - dy);
    return (sqrt(pow(dx, 2) + pow(dy, 2)));
}

int find_minimum(float *a)
{
  int c;
  int index = 0;
  int min = 100000;

  for (c = 1; c < 8; c++)
    if (a[c] < min) {
      index = c;
      min = a[c];
    }

  return index;
}

int calcul_all_pos(zappy_t *zap, client_t *cl, int i)
{
    int *p1 = calcul_p1(&zap->clients[i]);
    int *p2 = calcul_p2(&zap->clients[i]);
    int *p3 = calcul_p3(&zap->clients[i]);
    int *p4 = calcul_p4(&zap->clients[i]);
    int *p5 = calcul_p5(&zap->clients[i]);
    int *p6 = calcul_p6(&zap->clients[i]);
    int *p7 = calcul_p7(&zap->clients[i]);
    int *p8 = calcul_p8(&zap->clients[i]);
    float alldist[8] = {calcul_dcycl(zap, cl, p1[0], p1[1]),
    calcul_dcycl(zap, cl, p2[0], p2[1]), calcul_dcycl(zap, cl, p3[0], p3[1]),
    calcul_dcycl(zap, cl, p4[0], p4[1]), calcul_dcycl(zap, cl, p5[0], p5[1]),
    calcul_dcycl(zap, cl, p6[0], p6[1]),calcul_dcycl(zap, cl, p7[0], p7[1]),
    calcul_dcycl(zap, cl, p8[0], p8[1])};
    freep(&p1, &p2, &p3, &p4);
    freep2(&p5, &p6, &p7, &p8);
    return (find_minimum(alldist) + 1);
}

static void send_to_graph(zappy_t *zap, client_t *cl, char *arg)
{
    int err = 0;

    for (int i = 0; i < zap->nbClients; i++) {
        if (zap->clients[i].fd != -1 &&
        strcmp(zap->clients[i].team,"graphic") == 0) {
            char to_send[BUFFER_SIZE];
            err = snprintf(to_send, BUFFER_SIZE, "pbc %d %s\n", cl->fd, arg);
            check_snprintf(err, &zap->clients[i], to_send);
        }
    }
}

void broadcast(zappy_t *zap, client_t *cl, char *arg)
{
    int k = 0;
    char msg[BUFFER_SIZE];
    int err = 0;

    for (int i = 0; i < zap->nbClients; i++) {
        if (zap->clients[i].fd != cl->fd && zap->clients[i].fd != -1 &&
        strcmp(zap->clients[i].team, "graphic") != 0) {
            k = calcul_all_pos(zap, cl, i);
            err = snprintf(msg, BUFFER_SIZE, "message %d, %s\n", k, arg);
            check_snprintf(err, &zap->clients[i], msg);
        }
    }
    send_to_graph(zap, cl, arg);
    send_response(cl->fd, "ok\n");
}
