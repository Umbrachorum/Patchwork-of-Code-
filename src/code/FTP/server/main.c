/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** test.c
*/

#include "include/server.h"

int help()
{
    printf("%s\n" ,"Usage: ./server [port] [path]");
    printf("%s\n" ,"      port is the port number on which the server socket listens");
    printf("%s\n" ,"      path is the path to the home directory for the Anonymous user");
    return (ENDING);
}

int arg_check(int ac, char ** av, my_server *s)
{
    if(ac == 3 && strcmp(av[1], "-help") != 0 && strcmp(av[2], "-help") != 0) {
        if(init(s, av) == ERROR || binder(s) == ERROR || listener(s) == ERROR) {
            free(s);
            return ERROR;
        }
        return init_msg(s);
    }
    else {
        free(s);
        return (help());
    }
}

int main(int ac, char **av)
{
    my_server *s = malloc(sizeof(my_server));
    return arg_check(ac, av, s);
}