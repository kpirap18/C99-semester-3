#include "../inc/check_main.h"

START_TEST(tests_sum_matrix)
{
    double **matrix = allocate_matrix(2, 2);
    double **matrix1 = allocate_matrix(2, 2);
    double **matrix_res = allocate_matrix(2, 2);

    matrix[0][0] = 2;
    matrix[0][1] = 3;
    matrix[1][0] = 1;
    matrix[1][1] = 4;

    matrix1[0][0] = 1;
    matrix1[0][1] = 1;
    matrix1[1][0] = 1;
    matrix1[1][1] = 1;

    sum_matrix(matrix, matrix1, matrix_res, 2, 2);
    ck_assert_double_eq_tol(matrix_res[0][0], (double)3, EPS);
    ck_assert_double_eq_tol(matrix_res[0][1], (double)4, EPS);
    ck_assert_double_eq_tol(matrix_res[1][0], (double)2, EPS);
    ck_assert_double_eq_tol(matrix_res[1][1], (double)5, EPS);
    free(matrix);
    free(matrix1);
    free(matrix_res);
}
END_TEST
START_TEST(tests_sum_null_matrix)
{
    double **matrix = allocate_matrix(2, 3);
    double **matrix1 = allocate_matrix(2, 3);
    double **matrix_res = allocate_matrix(2, 3);

    matrix[0][0] = 0;
    matrix[0][1] = 0;
    matrix[0][2] = 0;
    matrix[1][0] = 0;
    matrix[1][1] = 0;
    matrix[1][2] = 0;

    matrix1[0][0] = 0;
    matrix1[0][1] = 0;
    matrix1[0][2] = 0;
    matrix1[1][0] = 0;
    matrix1[1][1] = 0;
    matrix1[1][2] = 0;

    sum_matrix(matrix, matrix1, matrix_res, 2, 3);
    ck_assert_double_eq_tol(matrix_res[0][0], (double)0, EPS);
    ck_assert_double_eq_tol(matrix_res[0][1], (double)0, EPS);
    ck_assert_double_eq_tol(matrix_res[0][2], (double)0, EPS);
    ck_assert_double_eq_tol(matrix_res[1][0], (double)0, EPS);
    ck_assert_double_eq_tol(matrix_res[1][1], (double)0, EPS);
    ck_assert_double_eq_tol(matrix_res[1][2], (double)0, EPS);
    free(matrix);
    free(matrix1);
    free(matrix_res);
}
END_TEST

Suite* sum_matrix_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("sum_matrix");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_sum_matrix);
    tcase_add_test(tc_pos, tests_sum_null_matrix);
    suite_add_tcase(s, tc_pos);

    return s;
}
