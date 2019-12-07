/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** calcul the inverse matrix of a matrix
*/

#include "103cipher.h"

int get_determinant(matrix_t *matrix)
{/*
    int det;

    if (matrix->height - line == 3) {
        det = matrix->m[0][0] + pow((-1), (i + j));
    }
det = matrix->m[0][0] * matrix->m[1][1] - matrix->m[0][1] * matrix->m[1][0];*/
    return 0;
}

int adjugate_matrix()
{
    return 0;
}

void transpose_matrix()
{

}

matrix_t *inverse_key(matrix_t *mkey)
{
    if (mkey->width == 2 && mkey->height == 2) {

    } else if (mkey->width == 3 && mkey->height == 3) {

    } else {
        fprintf(stderr, "ERROR: invalid size of mkey\n");
        exit(EXIT_ERROR);
    }
    return NULL;
}
