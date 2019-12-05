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
            printf("%.0f", matrix->m[y][x]);
            if (x != matrix->width - 1)
                printf("\t");
        }
        printf("\n");
    }
}

void display_mkey(matrix_t *mkey)
{
    printf("Key matrix:\n");
    print_matrix(mkey);
    printf("\n");
}

void display_coded_msg(matrix_t *coded_msg)
{
    printf("Encrypted message:\n");
    for (int y = 0; y < coded_msg->height; y++) {
        for (int x = 0; x < coded_msg->width; x++) {
            printf("%.0f", coded_msg->m[y][x]);
            if (x != (coded_msg->width - 1) || y != (coded_msg->height - 1))
                printf(" ");
        }
    }
    printf("\n");
}
