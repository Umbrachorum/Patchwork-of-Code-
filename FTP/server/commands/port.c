/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** test.c
*/

#include "../include/server.h"

int port_f(my_server *s)
{
    s->value = 210;
    printf("%s\n", "port");
    return STAY;
}