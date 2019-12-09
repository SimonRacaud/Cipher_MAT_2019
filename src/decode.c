/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** decode
*/

#include "103cipher.h"

void decode(matrix_t *key, matrix_t *msg)
{
    matrix_t *result;
    matrix_t *inv_key;

    if (key->width == 1 && key->height == 1) {
        if (key->m[0][0] == 0) {
            fprintf(stderr, "ERROR: the value of the key is null.\n");
            exit(EXIT_ERROR);
        }
        result = divide_matrix(msg, key->m[0][0]);
        display_mkey(key, 1);
    } else {
        inv_key = inverse_key(key);
        result = matrix_product(msg, inv_key);
        display_mkey(inv_key, 1);
        destroy_matrix(inv_key);
    }
    display_mmsg(result, 1);
    destroy_matrix(result);
}
