/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** test.c
*/

#include "../include/server.h"

int pasv_f(my_server *s)
{
    s->value = 210;
    printf("%s\n", "pasv");
    return STAY;
}