#include "../inc/my_main.h"
#include "../inc/io.h"
#include "../inc/initializmatrix.h"
#include "../inc/operationmatrix.h"


int main(int argc, char **argv)
{
    int rc = OK;
    setbuf(stdout, NULL);

    double **matrix1 = NULL;
    double **matrix2 = NULL;
    double **matrix_res = NULL;

    int n1, m1, n2, m2;


    if (argc == 5 && strcmp(argv[1], "a") == 0)
    {
        FILE *f_mat1 = fopen(argv[2], "r");

        if (f_mat1)
        {
            FILE *f_mat2 = fopen(argv[3], "r");

            if (f_mat2)
            {
                rc = read_matrix(f_mat1, matrix1, &n1, &m1);
                rc += read_matrix(f_mat2, matrix2, &n2, &m2);

                fclose(f_mat1);
                fclose(f_mat2);

                if (rc == OK && n1 == n2 && m1 == m2)
                {
                    matrix_res = allocate_matrix(n1, m1);

                    if (matrix_res)
                    {
                        sum_matrix(matrix1, matrix2, matrix_res, n1, m1);

                        free(matrix1);
                        free(matrix2);

                        FILE *f_res = fopen(argv[4], "w");
                        if (f_res)
                        {
                            print_matrix(f_res, matrix_res, n1, m1);
                            free(matrix_res);
                            fclose(f_res);
                        }
                        else
                        {
                            free(matrix_res);
                            rc = FILE_OPEN_ERR;
                        }
                    }
                    else
                    {
                        free(matrix1);
                        free(matrix2);
                        rc = MEMORY_ERR;
                    }
                }
                else
                {
                    free(matrix1);
                    free(matrix2);
                    rc = FILE_READ_ERR;
                }
            }
            else
            {
                fclose(f_mat1);
                rc = FILE_OPEN_ERR;
            }
        }
        else
        {
            rc = FILE_OPEN_ERR;
        }
    }
    else if (argc == 5 && strcmp(argv[1], "m") == 0)
    {
        FILE *f_mat1 = fopen(argv[2], "r");

        if (f_mat1)
        {
            FILE *f_mat2 = fopen(argv[3], "r");

            if (f_mat2)
            {
                rc = read_matrix(f_mat1, matrix1, &n1, &m1);
                rc += read_matrix(f_mat2, matrix2, &n2, &m2);

                fclose(f_mat1);
                fclose(f_mat2);

                if (rc == OK && m1 == n2)
                {
                    matrix_res = allocate_matrix(n1, m2);

                    if (matrix_res)
                    {
                        multi_matrix(matrix1, matrix2, matrix_res, n1, m1, m2);

                        free(matrix1);
                        free(matrix2);

                        FILE *f_res = fopen(argv[4], "w");
                        if (f_res)
                        {
                            print_matrix(f_res, matrix_res, n1, m1);
                            free(matrix_res);
                            fclose(f_res);
                        }
                        else
                        {
                            free(matrix_res);
                            rc = FILE_OPEN_ERR;
                        }
                    }
                    else
                    {
                        free(matrix1);
                        free(matrix2);
                        rc = MEMORY_ERR;
                    }
                }
                else
                {
                    free(matrix1);
                    free(matrix2);
                    rc = FILE_READ_ERR;
                }
            }
            else
            {
                fclose(f_mat1);
                rc = FILE_OPEN_ERR;
            }
        }
        else
        {
            rc = FILE_OPEN_ERR;
        }
    }
    else if (argc == 4 && strcmp(argv[1], "o") == 0)
    {
        FILE *f_mat1 = fopen(argv[2], "r");

        if (f_mat1)
        {
            rc = read_matrix(f_mat1, matrix1, &n1, &m1);

            if (rc == OK && n1 == m1)
            {
                double **mat2 = matrix1;

                matrix_res = allocate_matrix(n1, m1);
                if (matrix_res)
                {
                    null_one_matrix(matrix_res, n1, m1);

                    iverse_matrix(matrix_res, matrix1, n1);
                    FILE *f_res = fopen(argv[3], "w");
                    if (f_res)
                    {
                        print_matrix(f_res, matrix_res, n1, m1);
                        free(mat2);
                        fclose(f_res);
                    }
                    else
                    {
                        free(matrix1);
                        rc = FILE_OPEN_ERR;
                    }
                }
                else
                {
                    free(matrix1);
                    rc = MEMORY_ERR;
                }
            }
            else
            {
                fclose(f_mat1);
                rc = FILE_READ_ERR;
            }
        }
        else
        {
            rc = FILE_OPEN_ERR;
        }
    }
    return rc;
}
