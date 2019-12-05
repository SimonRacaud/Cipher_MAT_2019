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

    display_mkey(key);
    if (key->height > 1) {
        result = matrix_product(msg, key);
    } else {
        result = matrix_nbr_product(msg, key);
    }
    display_coded_msg(result);
    destroy_matrix(result);
}
