/*
В динамической матрице удалить строку с мин суммой элементов
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define OK 0

double **allocate_matrix(int n, int m)
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
}

int findminrow(double **matrix, int n, int m)
{
    double minsum = 0;
    int min_i = 0;

    for (int j = 0; j < m; ++j)
    {
        minsum += matrix[0][j];
    }

    double sum = 0;

    for (int i = 0; i < n; ++i)
    {
        sum = 0;
        for (int j = 1; j < m; ++j)
        {
            sum += matrix[i][j];
        }

        if (sum < minsum)
        {
            minsum = sum;
            min_i = i;
        }
    }

    return min_i;
}
void print_matrix(FILE *f, double **matrix, int n, int m)
{
    fprintf(f, "%d %d\n", n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fprintf(f, "%.6lf ", matrix[i][j]);
        }
        fprintf(f, "\n");
    }
}
void free_matrix(double **ptrs)
{
    free(ptrs[0]);
    free(ptrs);
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

int read_matrix(FILE *f, double ***matrix, int *n, int *m)
{
    int rc;
    double mat_val;
    double **tmp = NULL;

    rc = fscanf(f, "%d", n);
    if (rc != 1 || *n <= 0)
    {
        rc = -1;
        return rc;
    }

    rc = fscanf(f, "%d", m);
    if (rc != 1 || *m <= 0)
    {
        rc =-1;
        return rc;
    }

    rc = OK;    

    if (rc == OK)
    {
        tmp = allocate_matrix(*n, *m);
        if (tmp)
        {
            for (int i = 0; i < *n; i++)
            {
                for (int j = 0; j < *m; j++)
                {
                    rc = fscanf(f, "%lf", &mat_val);
                    if (rc != 1)
                    {
                        rc = -1;
                        return rc;
                    }
                    tmp[i][j] = mat_val;
                }
            }
            if (rc == 1)
            {
                *matrix = tmp;
                rc = OK;
            }
            else
            {
                free_matrix(tmp);
                *matrix = NULL;
                rc = -1;
            }
        }
    }
    else
    {
        rc = -1;
        *matrix = NULL;
    }

    return rc;
}

int del_row(double ***matrix, int n, int m)
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
int main()
{
    setbuf(stdout, NULL);
    int rc = OK;
    double **matrix = NULL;
    int n = 0, m = 0;
    double *tmp = NULL;
    int mini = 0;

    rc = read_matrix(stdin, &matrix, &n, &m);
    
    if (rc == OK)
    {
        fprintf(stdout, "Got matrix:\n");
        print_matrix(stdout, matrix, n, m);
        mini = findminrow(matrix, n, m);
        fprintf(stdout, "Min i %d:\n", mini);
        tmp = matrix[0];
        shift_rows(matrix, n, m, mini);

        print_matrix(stdout, matrix, n, m);
        del_row(&matrix, n, m);
        n = n - 1;
        fprintf(stdout, "Result matrix:\n");
        print_matrix(stdout, matrix, n, m);

        matrix[0] = tmp;
        free_matrix(matrix);
    }
    return rc;
}