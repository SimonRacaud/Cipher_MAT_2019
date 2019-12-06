/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** operation on matrix
*/

#include "103cipher.h"

static double do_product(matrix_t *ma, matrix_t *mb, int line, int column)
{
    double result = 0;

    for (int i = 0; i < ma->width; i++) {
        result += ma->m[line][i] * mb->m[i][column];
    }
    return result;
}

matrix_t *matrix_product(matrix_t *ma, matrix_t *mb)
{
    matrix_t *result = create_matrix(ma->width, ma->height);

    if (ma->width != mb->height)
        return NULL;
    result->width = ma->width;
    result->height = ma->height;
    for (int y = 0; y < ma->height; y++) {
        for (int x = 0; x < ma->width; x++) {
            result->m[y][x] = do_product(ma, mb, y, x);
        }
    }
    return result;
}

matrix_t *divide_matrix(matrix_t *ma, double nb)
{
    matrix_t *result = create_matrix(ma->width, ma->height);

    result->width = ma->width;
    result->height = ma->height;
    for (int y = 0; y < ma->height; y++) {
        for (int x = 0; x < ma->width; x++) {
            result->m[y][x] = ma->m[y][x] / nb;
        }
    }
    return result;
}
