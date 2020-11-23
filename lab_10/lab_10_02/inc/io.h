#ifndef _IO_H_
#define _IO_H_

#include "app.h"
#include "list.h"
#include "specialfunc.h"
#include "my_getline.h"

int inputcommand(FILE *stream, char *command);

int inputstring(FILE *stream, node_t **list);

void printdata(FILE *stream, char *string, int len);

void printlist(FILE *stream, node_t *list);

#endif // _IO_H_