/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** cipher
*/

#include "103cipher.h"

int cipher(char **arg)
{
    matrix_t *key;
    matrix_t *msg;

    if (arg[0][0] == '\0' || arg[1][0] == '\0') {
        fprintf(stderr, "ERROR: Arg one or two empty\n");
        return EXIT_ERROR;
    }
    if (strcmp(arg[2], "0") && strcmp(arg[2], "1")) {
        fprintf(stderr, "ERROR: invalid value of arg three\n");
        return EXIT_ERROR;
    }
    if (!strcmp(arg[2], "0")) {
        prepare_encode(&key, &msg, arg[1], arg[0]);
        encode(key, msg);
    } else if (!strcmp(arg[2], "1")) {
        prepare_decode(&key, &msg, arg[1], arg[0]);
        decode(key, msg);
    }
    destroy_matrix(key);
    destroy_matrix(msg);
    return EXIT_SUCCESS;
}
