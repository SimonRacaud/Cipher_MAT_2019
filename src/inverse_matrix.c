/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** calcul the inverse matrix of a matrix
*/

#include "103cipher.h"

static double get_determ_2_2(int x_exclude, int y_exclude,
const matrix_t *matrix)
{
    double abcd[4];
    int i_abcd = 0;
    for (int y = 0; y < matrix->height; y++) {
        for (int x = 0; x < matrix->width; x++) {
            if (y != y_exclude && x != x_exclude) {
                abcd[i_abcd++] = matrix->m[y][x];
            }
        }
    }
    return (abcd[0] * abcd[3] - abcd[1] * abcd[2]);
}

double get_determinant(const matrix_t *matrix)
{
    double det = 0;
    double **mtx = matrix->m;

    if (matrix->height > 2) {
        for (int x = 0; x < matrix->width; x++) {
            det += (pow((-1), x) * mtx[0][x]) * get_determ_2_2(x, 0, matrix);
        }
    } else if (matrix->height == 2) {
        det = mtx[0][0] * mtx[1][1] - mtx[0][1] * mtx[1][0];
    }
    return det;
}

matrix_t *adjugate_matrix(const matrix_t *matrix)
{
    matrix_t *com = create_matrix(matrix->width, matrix->height);

    for (int y = 0; y < matrix->height; y++) {
        for (int x = 0; x < matrix->width; x++) {
            if (matrix->width == 2)
                com->m[y][x] = pow((-1), (x + y)) * matrix->m[y][x];
            else
                com->m[y][x] = pow((-1), (x + y)) * get_determ_2_2(x, y, matrix);
        }
    }
    return com;
}

void transpose_matrix(matrix_t *matrix)
{
    if (matrix->height != matrix->width)
        return;
    for (int pos = 1; pos < matrix->height; pos++) {
        for (int i = 1; (pos - i) >= 0; i++) {
            swap(&matrix->m[pos - i][pos], &matrix->m[pos][pos - i]);
        }
    }
}

matrix_t *inverse_key(matrix_t *mkey)
{
    double det = get_determinant(mkey);
    matrix_t *com;
    matrix_t *inv_key;

    if (det == 0) {
        fprintf(stderr, "ERROR: determinant is null\n");
        exit(EXIT_ERROR);
    }
    if (mkey->width <= 3 && mkey->height <= 3 && mkey->width == mkey->height) {
        com = adjugate_matrix(mkey);
        if (mkey->width == 2)
            swap(&com->m[0][0], &com->m[1][1]);
        else
            transpose_matrix(com);
        inv_key = mul_matrix(com, (1 / det));
        destroy_matrix(com);
        return inv_key;
    } else {
        fprintf(stderr, "ERROR: invalid size of mkey\n");
        exit(EXIT_ERROR);
    }
    return NULL;
}
