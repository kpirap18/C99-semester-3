#ifndef APP_H
#define APP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <math.h>
#include <sys/types.h>

#define OK           0
#define POPERROR    -1
#define INSERTERROR -2
#define SORTERROR   -3
#define REVERROR    -4
#define NOTALLARG   -5
#define OPENERROR   -6
#define INVALID_ARG -7
#define MEMERROR    -8

#define MAXLEN     100

typedef struct node
{
    void *data;
    struct node *next;
} node_t;

typedef struct book
{
    char *name;
    char *author;
} book_r;

#endif // APP_H
