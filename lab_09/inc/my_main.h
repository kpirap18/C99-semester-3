#ifndef MY_MAIN_H
#define MY_MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RIGHT_NAMETITLE 25
#define MAX_LEN_TITLE       50
#define MAX_LEN_NAME        50
#define MAX_LEN_ARRAY       15
#define MAX_YEAR          2050
#define MIN_YEAR             0

#define OK                   0
#define NOT_ENOUGH_ARG      -6
#define OPEN_ERROR          -2
#define FILE_INVALID_ARG    42
#define NOT_FOUND           -3
#define INVALID_ARG         -4
#define READ_ERROR          -5

typedef struct
{
    char title[MAX_LEN_TITLE];
    char name[MAX_LEN_NAME];
    int year;
} film_r;


#endif // MY_MAIN_H
