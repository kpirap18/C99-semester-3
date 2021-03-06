#include "../inc/check_main.h"

START_TEST(tests_compare_less)
{
    int a = 2, b = 3;
    int *aa = &a, *bb = &b;
    int rc;

    rc = compare(aa, bb);
    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(tests_compare_null)
{
    int a = 3, b = 3;
    int *aa = &a, *bb = &b;
    int rc;

    rc = compare(aa, bb);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_compare_bigger)
{
    int a = 4, b = 3;
    int *aa = &a, *bb = &b;
    int rc;

    rc = compare(aa, bb);
    ck_assert_int_eq(rc, 1);
}
END_TEST

Suite* compare_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("compare");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_compare_less);
    tcase_add_test(tc_pos, tests_compare_null);
    tcase_add_test(tc_pos, tests_compare_bigger);
    suite_add_tcase(s, tc_pos);

    return s;
}
