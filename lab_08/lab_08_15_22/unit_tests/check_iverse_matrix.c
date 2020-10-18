#include "../inc/check_main.h"

START_TEST(tests_iverse_matrix)
{
    double **matrix = (double**)malloc(2 * sizeof(double*) + 2 * 2 *sizeof(double));
    double **matrix1 = (double**)malloc(2 * sizeof(double*) + 2 * 2 *sizeof(double));

    matrix[0][0] = 2;
    matrix[0][1] = 3;
    matrix[1][0] = 1;
    matrix[1][1] = 4;

    null_one_matrix(matrix1, 2, 2);
    iverse_matrix(matrix, matrix1, 2);
    ck_assert_double_eq_tol(matrix1[0][0], (double)0.8, EPS);
    ck_assert_double_eq_tol(matrix1[0][1], (double)-0.6, EPS);
    ck_assert_double_eq_tol(matrix1[1][0], (double)-0.2, EPS);
    ck_assert_double_eq_tol(matrix1[1][1], (double)0.4, EPS);
    free(matrix);
    free(matrix1);
}
END_TEST
START_TEST(tests_iverse_01_matrix)
{
    double **matrix = (double**)malloc(2 * sizeof(double*) + 2 * 2 *sizeof(double));
    double **matrix1 = (double**)malloc(2 * sizeof(double*) + 2 * 2 *sizeof(double));

    matrix[0][0] = 1;
    matrix[0][1] = 0;
    matrix[1][0] = 0;
    matrix[1][1] = 1;

    null_one_matrix(matrix1, 2, 2);
    iverse_matrix(matrix, matrix1, 2);
    ck_assert_double_eq_tol(matrix1[0][0], (double)1, EPS);
    ck_assert_double_eq_tol(matrix1[0][1], (double)0, EPS);
    ck_assert_double_eq_tol(matrix1[1][0], (double)0, EPS);
    ck_assert_double_eq_tol(matrix1[1][1], (double)1, EPS);
    free(matrix);
    free(matrix1);
}
END_TEST

Suite* iverse_matrix_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("iverse_matrix");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_iverse_matrix);
    tcase_add_test(tc_pos, tests_iverse_01_matrix);
    suite_add_tcase(s, tc_pos);

    return s;
}
