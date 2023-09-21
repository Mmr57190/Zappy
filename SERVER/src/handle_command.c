/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCY-4-1-myftp-lefeuvre.aristide
** File description:
** handleCommand
*/

#include "../include/commands.h"

void ptr_graphic(zappy_t *zap, client_t *cl, char *cmd)
{
    for (int i = 0; i < 7; i++)
        if (cmd != NULL && strncmp(cmd, COMMANDS_GRAPHIC[i].name, \
        strlen(COMMANDS_GRAPHIC[i].name)) == 0) {
            COMMANDS_GRAPHIC[i].ptr(zap, cl, strtok(NULL, "\0"));
            return;
        }
    if (cmd != NULL)
        send_response(cl->fd, "suc\n");
}

void ptr_ia(zappy_t *zap, client_t *cl, char *cmd)
{
    for (int i = 0; i < 9; i++) {
        if (cmd != NULL && strncmp(cmd, COMMANDS_AI[i].name, \
        strlen(COMMANDS_AI[i].name)) == 0) {
            COMMANDS_AI[i].ptr(zap, cl, strtok(NULL, "\0"));
            return;
        }
    }
    if (cmd != NULL)
        send_response(cl->fd, "ko\n");
}

void check_message(zappy_t *zap, client_t *cl, char *message, \
int message_len)
{
    if (message[message_len - 1] == '\n')
        message[message_len - 1] = '\0';
    char *tmp = strdup(message);
    char *cmd = strtok(tmp, " ");
    if (cl->nbCommands == 1) {
        choose_team(zap, cl, message);
    } else {
        if (strcmp(cl->team, "graphic") == 0) {
            ptr_graphic(zap, cl, cmd);
        } else {
            ptr_ia(zap, cl, cmd);
        }
    }
    free(tmp);
}

static void clear_cl(zappy_t *zap, client_t *cl, fd_set *readfds)
{
    pdi(zap, cl);
    rm_client_team(zap, cl);
    close(cl->fd);
    FD_CLR(cl->fd, readfds);
    cl->fd = -1;
}

void handle_client(zappy_t *zap, client_t *cl, fd_set *readfds)
{
    if (cl->fd == -1)
        return;
    static char message[BUFFER_SIZE] = {0};
    int message_len = strlen(message);
    int num_bytes = 0;

    if (FD_ISSET(cl->fd, readfds)) {
        num_bytes = read(cl->fd, message + message_len,
        BUFFER_SIZE - message_len);
        if (num_bytes == 0) {
            printf("i will kill %d %s\n", cl->fd, cl->team);
            clear_cl(zap, cl, readfds);
            return;
        }
        message_len += num_bytes;
        queue(zap, cl, message, message_len);
        memset(message, 0, BUFFER_SIZE);
    } else
        queue2(zap, cl, message);
}
