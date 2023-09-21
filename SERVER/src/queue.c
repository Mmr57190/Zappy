/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** queue
*/

#include "../include/server.h"

static void move_buff(client_t *cl)
{
    cl->cmd = strdup(cl->buffer[0]);
    if (strlen_tab(cl->buffer) == 1) {
        cl->buffer = NULL;
    } else {
        for (int i = 0; i < 9; i++)
            cl->buffer[i] = cl->buffer[i + 1];
        cl->buffer[9] = NULL;
    }
}

void queue1(zappy_t *zap, client_t *cl, char *message)
{
    if (cl->buffer == NULL) {
        cl->buffer = malloc(sizeof(char *) * 10);
        cl->buffer[0] = strdup(message);
        for (int i = 1; i < 10; i++)
            cl->buffer[i] = NULL;
    } else if (strlen_tab(cl->buffer) < 9)
        cl->buffer[strlen_tab(cl->buffer)] = strdup(message);
    if (cl->cmd != NULL)
        check_message(zap, cl, cl->cmd, strlen(cl->cmd));
    else {
        move_buff(cl);
        check_message(zap, cl, cl->cmd, strlen(cl->cmd));
    }
}

void queue2(zappy_t *zap, client_t *cl, char *message)
{
    if (cl->cmd == NULL && cl->buffer == NULL)
        return;
    if (cl->cmd != NULL)
        check_message(zap, cl, cl->cmd, strlen(cl->cmd));
    else if (cl->cmd == NULL && cl->buffer != NULL) {
        move_buff(cl);
        check_message(zap, cl, cl->cmd, strlen(cl->cmd));
    }
}

void queue(zappy_t *zap, client_t *cl, char *message, int message_len)
{
    if (cl->cmd == NULL && cl->buffer == NULL) {
        cl->cycle = 0;
        check_message(zap, cl, message, message_len);
        memset(message, 0, BUFFER_SIZE);
        return;
    } else
        queue1(zap, cl, message);
}
