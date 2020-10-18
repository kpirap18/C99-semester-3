#include "../inc/io.h"
#include "../inc/initializmatrix.h"

int read_info_mat(FILE *f, int *n, int *m)
{
    int rc = OK;

    rc = fscanf(f, "%d", n);
    if (rc != 1 || *n <= 0)
    {
        rc = FILE_READ_ERR;
        return rc;
    }

    rc = fscanf(f, "%d", m);
    if (rc != 1 || *m <= 0)
    {
        rc = FILE_READ_ERR;
        return rc;
    }

    return OK;
}

int read_matrix(FILE *f, double ***matrix, int *n, int *m)
{
    int rc;
    double mat_val;

    rc = read_info_mat(f, n, m);

    if (rc != OK)
        return FILE_READ_ERR;

    *matrix = allocate_matrix(*n, *m);

    if (!matrix)
        return MEMORY_ERR;

    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            rc = fscanf(f, "%lf", &mat_val);
            if (rc != 1)
            {
                rc = FILE_READ_ERR;
                return rc;
            }
            *matrix[i][j] = mat_val;
        }
    }

    return OK;
}

void print_matrix(FILE *f, double **matrix, int n, int m)
{
    fprintf(f, "%d %d\n", n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            fprintf(f, "%.6lf ", matrix[i][j]);
        fprintf(f, "\n");
    }
}
