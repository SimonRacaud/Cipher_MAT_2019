/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** utility tools
*/

#include "103cipher.h"

int count_nbr_from_str(char *str)
{
    int len = strlen(str);
    int counter = 0;
    int is_digit = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] >= '0' && str[i] <= '9' && !is_digit) {
            counter++;
            is_digit = 1;
        } else if (str[i] < '0' || str[i] > '9') {
            is_digit = 0;
        }
    }
    return counter;
}

void swap(double *a, double *b)
{
    double temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
