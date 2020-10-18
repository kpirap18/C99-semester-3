#include "../inc/check_main.h"

START_TEST(tests_read_simple)
{
    FILE *f = fopen("f1.txt", "r");

    if (f)
    {
        int n, m;

        int rc = read_info_mat(f, &n, &m);
        ck_assert_int_eq(rc, 0);
        ck_assert_int_eq(n, 4);
        ck_assert_int_eq(m, 8);
        fclose(f);
    }
}
END_TEST
START_TEST(tests_read_float)
{
    FILE *f = fopen("f2.txt", "r");

    if (f)
    {
        int n, m;

        int rc = read_info_mat(f, &n, &m);
        ck_assert_int_eq(rc, FILE_READ_ERR);
        fclose(f);
    }
}
END_TEST
START_TEST(tests_read_letter)
{
    FILE *f = fopen("f3.txt", "r");

    if (f)
    {
        int n, m;

        int rc = read_info_mat(f, &n, &m);
        ck_assert_int_eq(rc, FILE_READ_ERR);
        fclose(f);
    }
}
END_TEST
Suite* read_info_mat_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("read_info_mat");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, tests_read_float);
    tcase_add_test(tc_neg, tests_read_letter);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_read_simple);
    suite_add_tcase(s, tc_pos);

    return s;
}
