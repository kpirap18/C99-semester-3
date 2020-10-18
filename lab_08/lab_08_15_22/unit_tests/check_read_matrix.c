#include "../inc/check_main.h"

START_TEST(tests_read_all_simple)
{
    FILE *f = fopen("f11.txt", "r");

    if (f)
    {
        int n = 2, m = 2;
        double **matrix = allocate_matrix(n, m);

        null_matrix(matrix, n, m);
        int rc = read_matrix(f, matrix, n, m);
        ck_assert_int_eq(rc, 0);
        ck_assert_double_eq_tol(matrix[0][0], (double)1, EPS);
        ck_assert_double_eq_tol(matrix[0][1], (double)1, EPS);
        ck_assert_double_eq_tol(matrix[1][0], (double)1, EPS);
        ck_assert_double_eq_tol(matrix[1][1], (double)1, EPS);
        fclose(f);
        free(matrix);
    }
}
END_TEST
START_TEST(tests_read_all_float)
{
    FILE *f = fopen("f12.txt", "r");

    if (f)
    {
        int n = 2, m = 2;
        double **matrix = allocate_matrix(n, m);

        null_matrix(matrix, n, m);
        int rc = read_matrix(f, matrix, n, m);
        ck_assert_int_eq(rc, FILE_READ_ERR);
        fclose(f);
        free(matrix);
    }
}
END_TEST
START_TEST(tests_read_all_letter)
{
    FILE *f = fopen("f13.txt", "r");

    if (f)
    {
        int n = 2, m = 2;
        double **matrix = allocate_matrix(n, m);

        null_matrix(matrix, n, m);
        int rc = read_matrix(f, matrix, n, m);
        ck_assert_int_eq(rc, FILE_READ_ERR);
        fclose(f);
        free(matrix);
    }
}
END_TEST
Suite* read_matrix_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("read_matrix");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, tests_read_all_float);
    tcase_add_test(tc_neg, tests_read_all_letter);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_read_all_simple);
    suite_add_tcase(s, tc_pos);

    return s;
}
