/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** encode
*/

#include "103cipher.h"

void encode(matrix_t *key, matrix_t *msg)
{
    matrix_t *result;

    display_mkey(key, 0);
    result = matrix_product(msg, key);
    display_mmsg(result, 0);
    destroy_matrix(result);
}
