#ifndef APP_H
#define APP_H

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_YEAR          2050
#define MIN_YEAR             0

#define OK                   0
#define NOT_ENOUGH_ARG      -6
#define OPEN_ERROR          -2
#define FILE_INVALID_ARG    42
#define NOT_FOUND           -3
#define INVALID_ARG         -4
#define READ_ERROR          -5
#define MEMORY_ERR          -6

typedef struct
{
    char *title;
    char *name;
    int year;
} film_r;


#endif // MY_MAIN_H
