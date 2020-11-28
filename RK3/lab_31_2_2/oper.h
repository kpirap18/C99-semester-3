#ifndef _OPER_H_
#define _OPER_H_

#include "app.h"

int matrix_new(int **matrix, int n, int m);

int arr_len(int **matrix, int n, int m);

int *arr_new(int **matrix, int n, int m);

void arr_to_matrix(int **matrix, int *arr, int n, int m);

void matrix_to_arr(int **matrix, int *arr, int n, int m);

#endif // _OPER_H_