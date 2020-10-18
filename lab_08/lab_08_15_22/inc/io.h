#ifndef IO_H
#define IO_H

#include "my_main.h"

void print_matrix(FILE *f, double **matrix, int n, int m);

int read_matrix(FILE *f, double **matrix, int n, int m);

int read_info_mat(FILE *f, int *n, int *m);

#endif // IO_H
