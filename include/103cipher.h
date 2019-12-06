/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** header
*/

#ifndef H_CIPHER
#define H_CIPHER

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

int cipher(char **arg);

void prepare_encode(matrix_t **mkey, matrix_t **mmsg, char *key, char *msg);
void prepare_decode(matrix_t **mkey, matrix_t **mmsg, char *key, char *msg);

matrix_t *create_matrix(int width, int height);
void destroy_matrix(matrix_t *matrix);
void fill_matrix_from_str(matrix_t *matrix, char *str);
void fill_matrix_from_strnbr(matrix_t *matrix, char *str);
matrix_t *matrix_product(matrix_t *ma, matrix_t *mb);
matrix_t *divide_matrix(matrix_t *ma, double nb);

void encode(matrix_t *key, matrix_t *msg);

void print_matrix(matrix_t *matrix);
void display_mkey(matrix_t *mkey);
void display_mmsg(matrix_t *msg, int mode);

void decode(matrix_t *key, matrix_t *msg);

int count_nbr_from_str(char *str);

#endif
