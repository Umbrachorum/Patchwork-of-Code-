/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** test.c
*/

#include "../include/server.h"

int cmd_check(char *cmd, my_server *s)
{
    int idx = 0;
    int (*func_ptr[14])(my_server *s) ={user_f, pass_f, cwd_f, cpud_f, quit_f,
                                        dele_f, pwd_f, pasv_f, port_f, help_f, noop_f, retr_f, stor_f, list_f};
    char operate[][5] = {"USER", "PASS", "CWD", "CPUD",
                         "QUIT", "DELE", "PWD", "PASV", "PORT", "HELP" ,"NOOP", "RETR", "STOR", "LIST"};
    while(idx < 14) {
        if(strcmp(cmd, operate[idx]) == 10) {
            if(func_ptr[idx](s) == ENDING)
                return ENDING;
            else
                return STAY;
        }
        idx++;
    }
    s->value = 400;
    return ERROR;
}

int checker(my_server *s)
{
    if(cmd_check(s->client.msg, s) == ENDING){
        return ENDING;
    }
    if(cmd_check(s->client.msg, s) == ERROR) {
        dprintf(s->client_socket, "%d Wrong instruction\n", s->value);
        free(s->client.msg);
    }
    else {
        free(s->client.msg);
    }
    return STAY;
}

int init_msg(my_server *s)
{
    int fd;
    char message[DEFAULT_STR_SIZE];
    while (42) {
        if ((s->client_socket = accept(s->network_s, (struct sockaddr *) &s->server, &s->size)) < 0)
            return ERROR;
        if (fork() == 0) {
            fprintf(stderr, "<SP> Anonymous Connected <CRLF>\n");
            s->value = 220;
            dprintf(s->client_socket, "Connection Establishment\n");
            dprintf(s->client_socket, "%d\n", s->value);
            while((fd = read(s->client_socket, message, DEFAULT_STR_SIZE))) {
                s->client.msg = malloc(sizeof(char) *strlen(message));
                s->client.msg = strcpy(s->client.msg, message);
                if(checker(s) == ENDING)
                    return ENDING;
            }
        }
    }
}