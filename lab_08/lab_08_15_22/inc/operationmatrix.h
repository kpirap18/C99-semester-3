#ifndef OPERATIONMATRIX_H
#define OPERATIONMATRIX_H

#include "my_main.h"

void sum_matrix(double **mat1, double **mat2, double **mat_res, int n, int m);

void multi_matrix(double **mat1, double **mat2, double **mat_res, int n, int m, int q);

double det(double **a, int n);

void iverse_matrix(double **invmat, double **mat, int n);

#endif // OPERATIONMATRIX_H
