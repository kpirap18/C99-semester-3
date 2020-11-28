#ifndef _IO_H_
#define _IO_H_

#include "app.h"
#include "memory.h"

int read_size(FILE *f, int *n, int *m);

int read_matrix(FILE *f, int ***matrix, int n, int m);

void print(int **matrix, int n, int m);

void print_arr(int *a, int n);

#endif // _IO_H_
