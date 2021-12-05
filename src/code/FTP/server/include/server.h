/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** Server.h
*/


#ifndef SERVER_H_
#define SERVER_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <ctype.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include "../../utils/return.h"

typedef struct my_client {
    char *msg;
} my_client;

typedef struct my_server {
    int value;
    int network_s;
    char *path;
    int port;
    unsigned short sin_port;
    struct sockaddr_in server;
    my_client client;
    socklen_t size;
    int client_socket;
} my_server;

int cmd_check(char *cmd, my_server *s);
int user_f(my_server *s);
int pass_f(my_server *s);
int cwd_f(my_server *s);
int cpud_f(my_server *s);
int quit_f(my_server *s);
int dele_f(my_server *s);
int pwd_f(my_server *s);
int pasv_f(my_server *s);
int port_f(my_server *s);
int help_f(my_server *s);
int noop_f(my_server *s);
int retr_f(my_server *s);
int stor_f(my_server *s);
int list_f(my_server *s);

int init(my_server *s, char **av);
int check_int(char *str);
int listener(my_server *s);
int binder(my_server *s);
int init_msg(my_server *s);

#endif