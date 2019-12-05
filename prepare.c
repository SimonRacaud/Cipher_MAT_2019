/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** prepare the matrix
*/

#include "103cipher.h"

void get_msg_matrix_size(int *width, int *height, char *key, char *msg)
{
    int size = ceil(sqrt(strlen(key)));

    *width = size;
    *height = ceil(strlen(msg) / size);
}

void prepare(matrix_t **mkey, matrix_t **mmsg, char *key, char *msg)
{
    int width, height;

    get_msg_matrix_size(&width, &height, key, msg);
    *mkey = create_matrix(width, width);
    *mmsg = create_matrix(width, height);
    fill_matrix_from_str(*mkey, key);
    fill_matrix_from_str(*mmsg, msg);
}
