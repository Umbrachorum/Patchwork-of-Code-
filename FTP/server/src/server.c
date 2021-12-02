/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** test.c
*/

#include "../include/server.h"

int check_int(char *str)
{
    long unsigned int idx = 0;
    int sum = 0;
    while(idx < strlen(str)) {
        if(!isdigit(str[idx])) {
            return ERROR_CONVERT;
        }
        if(strlen(str) > 1) {
            sum = (sum * 10) + (str[idx] - '0');
        }
        else
            sum = str[idx]  - '0';
        idx++;
    }
    return sum;
}

int conditions(my_server *s, char **av)
{
    if (chdir(s->path) == -1) {
        printf("%s\n", "something wrong when chdir path");
        return (ERROR);
    }
    if((s->port = check_int(av[1])) < 0){
        printf("%s\n", "something wrong with port conversion");
        return (ERROR);
    }
    return ENDING;
}

int init(my_server *s, char **av)
{
    s->path = av[2];
    s->size = sizeof(s->size);
    if(conditions(s, av) != ENDING)
        return ERROR;
    s->server.sin_family = AF_INET;
    s->sin_port = s->port;
    s->server.sin_port = htons(s->port);
    s->server.sin_addr.s_addr = INADDR_ANY;
    if((s->network_s = socket(AF_INET, SOCK_STREAM , 0)) < 0) {
        printf("%s\n", "something wrong with socket creation");
        return (ERROR);
    }
    if(setsockopt(s->network_s, SOL_SOCKET, SO_REUSEPORT,  &(int){1}, sizeof(int)) < 0)
        return (ERROR);
    return (ENDING);
}

int binder(my_server *s)
{
    if (bind(s->network_s, (const struct sockaddr *) &s->server, sizeof(s->server)) < 0) {
        close(s->network_s);
        return (ERROR);
    }
    return ENDING;
}

int listener(my_server *s)
{
    if (listen(s->network_s, 10) < 0) {
        close(s->network_s);
        return (ERROR);
    }
    return ENDING;
}