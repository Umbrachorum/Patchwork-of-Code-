/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** test.c
*/

#include "../include/server.h"

int user_f(my_server *s)
{
    s->value = 240;
    printf("%s\n", "user");
    return STAY;
}