/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** test.c
*/

#include "../include/server.h"

int cpud_f(my_server *s) {
    s->value = 210;
    printf("%s\n", "cpud");
    return STAY;
}