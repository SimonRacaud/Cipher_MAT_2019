/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** prepare the matrix
*/

#include "103cipher.h"

void prepare_encode(matrix_t **mkey, matrix_t **mmsg, char *key, char *msg)
{
    int width, height;
    int key_size = ceil(sqrt(strlen(key)));

    width = key_size;
    height = ceil((double)strlen(msg) / key_size);
    *mkey = create_matrix(key_size, key_size);
    *mmsg = create_matrix(width, height);
    fill_matrix_from_str(*mkey, key);
    fill_matrix_from_str(*mmsg, msg);
}

void prepare_decode(matrix_t **mkey, matrix_t **mmsg, char *key, char *msg)
{
    int width, height;
    int key_size = ceil(sqrt(strlen(key)));

    width = key_size;
    height = ceil((double)count_nbr_from_str(msg) / key_size);
    *mkey = create_matrix(width, width);
    *mmsg = create_matrix(width, height);
    fill_matrix_from_str(*mkey, key);
    fill_matrix_from_strnbr(*mmsg, msg);
}
