#include "../inc/check_main.h"

START_TEST(tests_null_one_matrix)
{
    double **matrix = allocate_matrix(2, 2);

    null_one_matrix(matrix, 2, 2);
    ck_assert_double_eq_tol(matrix[0][0], (double)1, EPS);
    ck_assert_double_eq_tol(matrix[0][1], (double)0, EPS);
    ck_assert_double_eq_tol(matrix[1][0], (double)0, EPS);
    ck_assert_double_eq_tol(matrix[1][1], (double)1, EPS);
    free(matrix);
}
END_TEST

Suite* null_one_matrix_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("null_one_matrix");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_null_one_matrix);
    suite_add_tcase(s, tc_pos);

    return s;
}
