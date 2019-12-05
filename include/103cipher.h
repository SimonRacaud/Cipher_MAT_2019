/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** header
*/

#ifndef H_CYPHER
#define H_CYPHER

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>

#define EXIT_ERROR 84
#define EXIT_SUCCESS 0

typedef struct matrix {
    double **m;
    int height;
    int width;
} matrix_t;

int cipher(char **arg, int argc);

void prepare(matrix_t **mkey, matrix_t **mmsg, char *key, char *msg);

matrix_t *create_matrix(int width, int height);
void fill_matrix_from_str(matrix_t *matrix, char *str);
void destroy_matrix(matrix_t *matrix);
matrix_t *matrix_product(matrix_t *ma, matrix_t *mb);

void encode(matrix_t *key, matrix_t *msg);

void print_matrix(matrix_t *matrix);
void display_mkey(matrix_t *mkey);

#endif
