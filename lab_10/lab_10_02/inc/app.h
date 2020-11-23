#ifndef _APP_H_
#define _APP_H_

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

#define OK              0
#define INPUTERROR     -1
#define COMMANDERROR   -2
#define NOTALLARG      -3
#define MEMERROR       -4
#define NOTPOS         -5

#define LENCOMMAND     10
#define LENSTATICSTR    4

typedef struct node
{
    char string[LENSTATICSTR];
    struct node *next;
} node_t;

#endif // _APP_H_
