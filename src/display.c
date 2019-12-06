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

void display_mmsg(matrix_t *msg, int mode)
{
    if (mode == 0)
        printf("Encrypted message:\n");
    else
        printf("Decrypted message:\n");
    for (int y = 0; y < msg->height; y++) {
        for (int x = 0; x < msg->width; x++) {
            if (mode == 0) {
                printf("%.0f", msg->m[y][x]);
                if (x != (msg->width - 1) || y != (msg->height - 1))
                    printf(" ");
            } else
                printf("%c", (char)msg->m[y][x]);
        }
    }
    printf("\n");
}
