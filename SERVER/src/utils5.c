/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** utils5
*/

#include "../include/server.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *str = malloc(sizeof(char) * (strlen(dest) + strlen(src) + 1));

    if (str == NULL)
        return NULL;
    while (dest[i] != '\0') {
        str[i] = dest[i];
        i++;
    }
    while (src[j] != '\0') {
        str[i] = src[j];
        j++;
        i++;
    }
    str[i] = '\0';
    free(dest);
    return str;
}

int cgpX(int x, int etage, zappy_t *zap)
{
    int finalX = 0;

    if (x < 0) {
        finalX = (zap->map->x - 1) - (etage - 1);
    } else if (x > zap->map->x - 1) {
        finalX = 0 + (etage - 1);
    } else
        finalX = x;
    return finalX;
}

int cgpY(int y, int etage, zappy_t *zap)
{
    int finalY = 0;

    if (y < 0) {
        finalY = (zap->map->y - 1) - (etage - 1);
    } else if (y > zap->map->y - 1) {
        finalY = 0 + (etage - 1);
    } else
        finalY = y;
    return finalY;
}

void plv_tograph(zappy_t *zap, client_t *cl)
{
    int err = 0;

    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (zap->clients[i].fd != -1 &&
        strcmp(zap->clients[i].team, "graphic") == 0) {
            char to_send[BUFFER_SIZE];
            int r = fcntl(zap->clients[i].fd, F_GETFL);
            if (r == -1)
                break;
            err = snprintf(to_send, BUFFER_SIZE,"plv %d %d\n", cl->fd, cl->level);
            check_snprintf(err, &zap->clients[i],to_send);
        }
    }
}

client_t *get_client(zappy_t *zap, int fd, int level, char *str)
{
    for (int i = 0; i < zap->nbClients; i++)
        if (zap->clients[i].fd == fd) {
            zap->clients[i].level = level;
            zap->clients[i].cmd = NULL;
            zap->clients[i].cycle = 0;
            zap->clients[i].buffer = NULL;
            send_response(zap->clients[i].fd, str);
            return (&zap->clients[i]);
        }
    return (NULL);
}