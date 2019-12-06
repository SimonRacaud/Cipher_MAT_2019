/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** main
*/

#include "103cipher.h"

int usage(int status)
{
    printf("USAGE\n\t./103cipher message key flag\n\nDESCRIPTION\n\t");
    printf("message\ta message, made of ASCII characters\n\t");
    printf("key\tthe encryption key, made of ASCII characters\n\t");
    printf("flag\t0 for the message to be encrypted, 1 to be decrypted\n");
    return status;
}

int main(int argc, char **argv)
{
    if (argc == 4) {
        return cipher(argv + 1);
    } else {
        return usage(84);
    }
}
