#include "../inc/my_main.h"
#include "../inc/io.h"
#include "../inc/initializmatrix.h"
#include "../inc/operationmatrix.h"


int main(int argc, char **argv)
{
    int rc = OK;

    if (argc == 5 && (strcmp(argv[1], "a") == 0 || strcmp(argv[1], "m") == 0))
    {
        FILE *f_mat1;
        f_mat1 = fopen(argv[2], "r");
        if (f_mat1)
        {
            FILE *f_mat2;
            f_mat2 = fopen(argv[3], "r");

            if (f_mat2)
            {
                int n1, m1, n2, m2;
                rc = read_info_mat(f_mat1, &n1, &m1);
                rc += read_info_mat(f_mat2, &n2, &m2);

                if (rc == OK)
                {
                    double **matrix1 = allocate_matrix(n1, m1);

                    if (matrix1)
                    {
                        double **matrix2 = allocate_matrix(n2, m2);
                        if (matrix2)
                        {
                            null_matrix(matrix1, n1, m1);
                            null_matrix(matrix2, n2, m2);

                            rc = read_matrix(f_mat1, matrix1, n1, m1);
                            rc += read_matrix(f_mat2, matrix2, n2, m2);

                            fclose(f_mat1);
                            fclose(f_mat2);

                            if (rc == OK && strcmp(argv[1], "a") == 0 && n1 == n2 && m1 == m2)
                            {
                                double **matrix_res = allocate_matrix(n1, m1);

                                if (matrix_res)
                                {
                                    sum_matrix(matrix1, matrix2, matrix_res, n1, m1);

                                    FILE *f_res;
                                    f_res = fopen(argv[4], "w");
                                    if (f_res)
                                    {
                                        print_matrix(f_res, matrix_res, n1, m1);

                                        fclose(f_res);
                                    }
                                    else
                                    {
                                        rc = FILE_OPEN_ERR;
                                    }
                                    free(matrix_res);
                                }
                                else
                                {
                                    rc = MEMORY_ERR;
                                }
                            }
                            else if (rc == OK && strcmp(argv[1], "m") == 0 && m1 == n2)
                            {
                                double **matrix_res = allocate_matrix(n1, m2);

                                if (matrix_res)
                                {
                                    multi_matrix(matrix1, matrix2, matrix_res, n1, m1, m2);

                                    FILE *f_res;
                                    f_res = fopen(argv[4], "w");
                                    if (f_res)
                                    {
                                        print_matrix(f_res, matrix_res, n1, m2);

                                        fclose(f_res);
                                    }
                                    else
                                    {
                                        rc = FILE_OPEN_ERR;
                                    }
                                    free(matrix_res);
                                }
                                else
                                {
                                    rc = MEMORY_ERR;
                                }
                            }
                            else
                            {
                                rc = FILE_READ_ERR;
                            }
                            free(matrix1);
                            free(matrix2);
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
                        fclose(f_mat2);
                        rc = MEMORY_ERR;
                    }
                }
                else
                {
                    fclose(f_mat1);
                    fclose(f_mat2);
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
    else if (argc == 4 && (strcmp(argv[1], "o") == 0))
    {
        FILE *f_mat1;
        f_mat1 = fopen(argv[2], "r");

        if (f_mat1)
        {
            int n1, m1;
            rc = read_info_mat(f_mat1, &n1, &m1);

            if (rc == OK)
            {
                double **matrix1 = allocate_matrix(n1, m1);

                if (matrix1)
                {
                    null_matrix(matrix1, n1, m1);

                    rc = read_matrix(f_mat1, matrix1, n1, m1);
                    fclose(f_mat1);

                    if (rc == OK && n1 == m1)
                    {
                        double **matrix_res = allocate_matrix(n1, m1);

                        if (matrix_res)
                        {
                            null_one_matrix(matrix_res, n1, m1);

                            double **mat_res2 = allocate_matrix(n1, m1);
                            matrix_copy(matrix1, mat_res2, n1);
                            double ddet = det(matrix1, n1);
                            free(matrix1);

                            if (fabs(ddet - 0) > EPS)
                            {
                                iverse_matrix(matrix_res, mat_res2, n1);

                                FILE *f_res;
                                f_res = fopen(argv[3], "w");
                                if (f_res)
                                {
                                    print_matrix(f_res, matrix_res, n1, m1);

                                    fclose(f_res);
                                }
                                else
                                {
                                    rc = FILE_OPEN_ERR;
                                }
                            }
                            else
                            {
                                rc = SUM_ERR;
                            }
                            free(mat_res2);
                            free(matrix_res);
                        }
                        else
                        {
                            free(matrix1);
                            rc = MEMORY_ERR;
                        }
                    }
                    else
                    {
                        free(matrix1);
                        rc = FILE_READ_ERR;
                    }
                }
                else
                {
                    fclose(f_mat1);
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
    else
    {
        rc = INV_ARG_ERR;
    }

    return rc;
}
