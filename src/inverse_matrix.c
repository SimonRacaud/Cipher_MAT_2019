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
            com->m[y][x] = pow((-1), (x + y)) * get_determ_2_2(x, y, matrix);
        }
    }
    return com;
}

void transpose_matrix(matrix_t *matrix)
{
    for (int y = 1; y < matrix->height; y++) {
        for (int x = 1; x < matrix->width; x++) {
            
        }
    }
}

matrix_t *inverse_key(matrix_t *mkey)
{
    //print_matrix(mkey);
    int det = get_determinant(mkey);
    matrix_t *com;

    if (mkey->width == 2 && mkey->height == 2) {

    } else if (mkey->width == 3 && mkey->height == 3) {
        com = adjugate_matrix(mkey);
        transpose_matrix(com);
        destroy_matrix(com);
    } else {
        fprintf(stderr, "ERROR: invalid size of mkey\n");
        exit(EXIT_ERROR);
    }
    return NULL;
}
