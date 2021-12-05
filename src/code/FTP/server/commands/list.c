/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** test.c
*/

#include "../include/server.h"

int list_f(my_server *s) {
    s->value = 210;
    printf("%s\n", "list");
    return STAY;
}
