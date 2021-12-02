/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** test.c
*/

#include "../include/server.h"
#include <signal.h>

int quit_f(my_server *s) {
    s->value = 230;
    dprintf(s->client_socket,"%d\n", s->value);
    fprintf(stderr, "<SP> User leaver <CRLF>\n");
    close(s->network_s);
    shutdown(s->client_socket, SHUT_RDWR);
    free(s);
    return ENDING;
}