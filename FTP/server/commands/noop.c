/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** test.c
*/

#include "../include/server.h"

int noop_f(my_server *s)
{
    s->value = 210;
    printf("%s\n", "noop");
    return STAY;
}