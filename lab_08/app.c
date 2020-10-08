#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define OK 0
#define FILE_OPEN_ERR -1
#define FILE_READ_ERR -2
#define SUM_ERR -3
#define MULTI_ERR -4

double** allocate_matrix(int n, int m)
{
    double **data = (double**)malloc(n * sizeof(double*) + n * m * sizeof(double));

    if (!data)
        return NULL;

    for (int i = 0; i < n; i++)
        data[i] = (double*)((char*)data + n * sizeof(double*) + i * m * sizeof(double));

    return data;
}

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
int read_matrix(FILE *f, double **matrix, int n, int m)
{
    int rc;
    double mat_val;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            rc = fscanf(f, "%lf", &mat_val);
            if (rc != 1)
            {
                rc = FILE_READ_ERR;
                return rc;
            }
            matrix[i][j] = mat_val;
        }
    }


    return OK;
}
void print_matrix(double **matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%lf ", matrix[i][j]);
        printf("\n");
    }

}
void null_matrix(double **matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] = 0;

}

void sum_matrix(double **mat1, double **mat2, double **mat_res, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mat_res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}
void multi_matrix(double **mat1, double **mat2, double **mat_res, int n, int m, int q)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            mat_res[i][j] = 0;
            for(int k = 0; k < q; k++)
            {
                mat_res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
void iverse_matrix(double **invmat, double **mat, int n)
{
    int  i, j, k, z;
    double r, res;

    for (k = 0; k < n; k++)
    {
        r = 1/mat[k][k];
        for (j = 0; j < n; j++)
        {
            mat[k][j] *= r;
            invmat[k][j] *= r;
        }
        for (i =k +1; i < n; i++)
        {
            res = mat[i][k];
            for (z = 0; z < n; z++)
            {
                mat[i][z] -= mat[k][z]*res;
                invmat[i][z] -= invmat[k][z]*res;
            }
        }
    }
    for (k = n - 1; k >= 0; k--)
    {
        for (i = k - 1; i >= 0; i--)
        {
            res = mat[i][k];
            for (z = n - 1; z >= 0; z--)
            {
                mat[i][z] = mat[i][z] - mat[k][z]*res;
                invmat[i][z] = invmat[i][z] - invmat[k][z]*res;
            }

        }
    }
}
int main(/*int argc, char **argv*/)
{
    int argc = 5;
    char argv[12][1111] = {"app.exe", "m", "C:/msys64/home/Ira/cprog/lab_08/f_mat1.txt", "C:/msys64/home/Ira/cprog/lab_08/f_mat2.txt", "res.txt"};

    int rc = OK;

    if (argc == 5 && (strcmp(argv[1], "a") || strcmp(argv[1], "m")))
    {
        FILE *f_mat1, *f_mat2;
        f_mat1 = fopen(argv[2], "r");
        f_mat2 = fopen(argv[3], "r");

        if (f_mat1 && f_mat2)
        {
            int n1, m1, n2, m2;
            rc = read_info_mat(f_mat1, &n1, &m1) + read_info_mat(f_mat2, &n2, &m2);
            if (rc == OK)
            {
                double **matrix1 = allocate_matrix(n1, m1);
                null_matrix(matrix1, n1, m1);
                rc = read_matrix(f_mat1, matrix1, n1, m1);
                print_matrix(matrix1, n1, m1);

                double **matrix2 = allocate_matrix(n2, m2);
                null_matrix(matrix2, n2, m2);
                rc = read_matrix(f_mat2, matrix2, n2, m2);
                print_matrix(matrix2, n2, m2);

                if (strcmp(argv[1], "a") == 0)
                {
                    if (n1 == n2 && m1 == m2)
                    {
                        double **matrix_res = allocate_matrix(n1, m1);
                        sum_matrix(matrix1, matrix2, matrix_res, n1, m1);
                        print_matrix(matrix_res, n1, m1);
                    }
                    else
                    {
                        rc = SUM_ERR;
                    }
                }

                if (strcmp(argv[1], "m") == 0)
                {
                    if (m2 == n1)
                    {
                        double **matrix_res = allocate_matrix(n1, m1);
                        multi_matrix(matrix1, matrix2, matrix_res, n1, m1, m2);
                        print_matrix(matrix_res, n1, m1);
                    }
                    else
                    {
                        rc = MULTI_ERR;
                    }
                }
                
                if (strcmp(argv[1] ,"o") == 0)
                {
                    double **matrix_res = allocate_matrix(n1, m1);
                }
            }
        }
    }


    return rc;
}
