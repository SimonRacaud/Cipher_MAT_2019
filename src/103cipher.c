/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** cipher - main function
*/

#include "103cipher.h"

static const char *ERR_ARG_EMPTY = "ERROR: Arg one or two empty\n";
static const char *ERR_ARG_INVALID = "ERROR: invalid value of arg three\n";

int cipher(char **arg)
{
    matrix_t *key;
    matrix_t *msg;

    if (arg[0][0] == '\0' || arg[1][0] == '\0') {
        fprintf(stderr, ERR_ARG_EMPTY);
        return EXIT_ERROR;
    }
    if (strcmp(arg[2], "0") && strcmp(arg[2], "1")) {
        fprintf(stderr, ERR_ARG_INVALID);
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
