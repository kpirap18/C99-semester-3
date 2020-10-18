#ifndef MEMORY_H
#define MEMORY_H

#include "my_main.h"

double **allocate_matrix(int n, int m);

void null_matrix(double **matrix, int n, int m);

void null_one_matrix(double **matrix, int n, int m);

void matrix_copy(double **mat1, double **mat_copy, int n);

#endif // MEMORY_H
