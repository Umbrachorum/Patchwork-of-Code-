/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** test.c
*/

#include "../include/server.h"

int retr_f(my_server *s)
{
    s->value = 240;
    printf("%s\n", "retr");
    return STAY;
}