#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define OK 0

void print(double **matrix, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            printf("%.6lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

/*double **allocate_matrix(int n, int m)
{
    double **ptrs, *data;

    ptrs = malloc(n * sizeof(double*));

    if (!ptrs)
    {
        return NULL;
    }

    data = malloc(n * m * sizeof(double));

    if (!data)
    {
        free(ptrs);
        return NULL;
    }

    for (int i = 0; i < n; ++i)
    {
        ptrs[i] = data + i * m;
    }

    return ptrs;
}*/

double **allocate_matrix(int n, int m)
{
    double **data = (double**)malloc(n * sizeof(double*) + n * m * sizeof(double));

    if (!data)
        return NULL;

    for (int i = 0; i < n; i++)
        data[i] = (double*)((char*)data + n * sizeof(double*) + i * m * sizeof(double));

    return data;
}

void full_matrix(double **matrix, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            matrix[i][j] = i + 1;
        }
    }
}

void shift_rows(double **matrix, int n, int m, int row)
{
    double *tmp;

    for (int i = row; i < n - 1; ++i)
    {
        tmp = matrix[i];
        matrix[i] = matrix[i + 1];
        matrix[i + 1] = tmp;
    }
}

void shift_col(double **matrix, int n, int m, int col)
{
    int tmp;

    for (int i = 0; i < n; ++i)
    {
        for (int j = col; j < m - 1; ++j)
        {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[i][j + 1];
            matrix[i][j + 1] = tmp;
        }
    }
}

/*int del_row(double ***matrix, int n, int m)
{
    //ree(matrix[n - 1]);

    double **tmp = realloc(*matrix, sizeof(double *) * (n - 1) * m);

    if (!tmp)
    {
        return -1;
    }

    *matrix = tmp;

    return OK;
}

int del_col(double ***matrix, int n, int m)
{
    double **tmp = realloc(*matrix, sizeof(double *) * (m - 1) * n);

    if (!tmp)
    {
        return -1;
    }

    *matrix = tmp;

    return OK;
}*/

int del_row(double ***matrix, int n, int m)
{
    double **tmp = realloc(*matrix, (n - 1) * sizeof(double*) + (n - 1) * m * sizeof(double));

    if (!tmp)
    {
        return -1;
    }

    for (int i = 0; i < n - 1; i++)
        tmp[i] = (double*)((char*)tmp + (n - 1) * sizeof(double*) + i * m * sizeof(double));

    *matrix = tmp;
    return OK;
}

int del_col(double ***matrix, int n, int m)
{
    double **tmp = realloc(*matrix, n * sizeof(double*) + n * (m - 1) * sizeof(double));

    if (!tmp)
    {
        return -1;
    }

    for (int i = 0; i < n; i++)
        tmp[i] = (double*)((char*)tmp + n * sizeof(double*) + i * (m - 1) * sizeof(double));

    *matrix = tmp;
    return OK;
}

void free_matrix(double **matrix)
{
    free(matrix[0]);
    free(matrix);
}

int main()
{
    double **matrix_1 = NULL;
    int n = 5, m = 5;

    matrix_1 = allocate_matrix(n, m);

    if (matrix_1)
    {
        full_matrix(matrix_1, n, m);
        print(matrix_1, n, m);
        printf("\n\n");

        shift_rows(matrix_1, n, m, 3);
        print(matrix_1, n, m);
        printf("\n\n");

        int rc = del_row(&matrix_1, n, m);
        n = n - 1;
        print(matrix_1, n, m);
        printf("\n\n");
        printf("rc = %d\n", rc);

        // shift_col(matrix_1, n, m, 0);
        // print(matrix_1, n, m);
        // printf("\n\n");

        rc = del_col(&matrix_1, n, m);
        m = m - 1;
        print(matrix_1, n, m);
        printf("\n\n");
        printf("rc = %d\n", rc);

        //free_matrix(matrix_1);
        free(matrix_1);
    }
    return OK;
}
