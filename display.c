/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** display result
*/

#include "103cipher.h"

void print_matrix(matrix_t *matrix)
{
    for (int y = 0; y < matrix->height; y++) {
        for (int x = 0; x < matrix->width; x++) {
            printf("%hf", matrix->m[y][x]);
            if (x != matrix->width - 1)
                printf("\t");
        }
    }
}

void display_mkey(matrix_t *mkey)
{
    printf("Key matrix:\n");
    print_matrix(mkey);
    printf("\n");
}
