#include "io.h"

int read_size(FILE *f, int *n, int *m)
{
    int rc = OK;

    rc = fscanf(f, "%d", n);
    if (rc != 1 || *n <= 0)
    {
        rc = INPUTERROR;
        return rc;
    }

    rc = fscanf(f, "%d", m);
    if (rc != 1 || *m <= 0)
    {
        rc = INPUTERROR;
        return rc;
    }

    if (rc != INPUTERROR)
    {
        rc = OK;
    }

    return OK;
}
int read_matrix(FILE *f, int ***matrix, int n, int m)
{
    int rc = OK;
    int mat;
    int **tmp = NULL;

    tmp = allocate_matrix(n, m);
    if (tmp)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (fscanf(f, "%d", &mat)!= 1)
                {
                    rc = INPUTERROR;
                }
                tmp[i][j] = mat;
            }
        }
        if (rc != INPUTERROR)
        {
            rc = OK;
        }
        *matrix = tmp;
    }
    else
    {
        *matrix = NULL;
        rc = MEMERROR;
    } 

    return rc;
}

void print(int **matrix, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_arr(int *a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}