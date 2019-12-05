/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** matrix
*/

#include "103cipher.h"

matrix_t *create_matrix(int width, int height)
{
    matrix_t *matrix = malloc(sizeof(matrix_t));

    if (!matrix)
        return NULL;
    matrix->m = malloc(sizeof(double) * height);
    if (!matrix->m)
        return NULL;
    for (int i = 0; i < height; i++) {
        matrix->m[i] = malloc(sizeof(double) * width);
        if (!matrix->m[i])
            return NULL;
    }
    matrix->width = width;
    matrix->height = height;
    return matrix;
}

void fill_matrix_from_str(matrix_t *matrix, char *str)
{
    int len = strlen(str);
    int i = 0;

    for (int y = 0; y < matrix->height; y++) {
        for (int x = 0; x < matrix->width; x++) {
            if (i < len) {
                matrix->m[y][x] = (double)str[i];
                i++;
            } else
                matrix->m[y][x] = 0;
        }
    }
}

void destroy_matrix(matrix_t *matrix)
{
    for (int i = 0; i < matrix->height; i++)
        free(matrix->m[i]);
    free(matrix->m);
    free(matrix);
}

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

matrix_t *matrix_nbr_product(matrix_t *ma, matrix_t *mb)
{
    matrix_t *result = create_matrix(ma->width, ma->height);

    if (ma->width != mb->height)
        return NULL;
    result->width = ma->width;
    result->height = ma->height;
    for (int y = 0; y < ma->height; y++) {
        for (int x = 0; x < ma->width; x++) {
            result->m[y][x] = ma->m[y][x] * mb->m[0][0];
        }
    }
    return result;
}
