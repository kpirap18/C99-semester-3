#include "../inc/initializmatrix.h"

double **allocate_matrix(int n, int m)
{
    double **data = (double**)malloc(n * sizeof(double*) + n * m * sizeof(double));

    if (!data)
        return NULL;

    for (int i = 0; i < n; i++)
        data[i] = (double*)((char*)data + n * sizeof(double*) + i * m * sizeof(double));

    return data;
}

void null_matrix(double **matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] = 0;
}

void null_one_matrix(double **matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }
}

void matrix_copy(double **mat1, double **mat_copy, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat_copy[i][j] = mat1[i][j];
        }
    }
}

