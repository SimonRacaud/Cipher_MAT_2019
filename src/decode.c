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

    if (key->width == 1 && key->height == 1)
        result = divide_matrix(msg, key->m[0][0]);
    display_mkey(key);
    display_mmsg(result, "Decrypted message:\n");
    destroy_matrix(result);
}
