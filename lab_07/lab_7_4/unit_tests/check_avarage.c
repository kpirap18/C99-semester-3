#include "../inc/check_main.h"

START_TEST(tests_ava_usual)
{
    int *pb_src, *pe_src;
    int a[3] = {1, 1, 1};
    pb_src = a;
    pe_src = a;
    double rc;

    rc = avarage(pb_src, pe_src);
    ck_assert_double_eq(rc, 1);
    free(pb_src);
}
END_TEST

START_TEST(tests_float_res)
{
    int *pb_src, *pe_src;
    int a[5] = {1, 4, 8, 5, 5};
    pb_src = a;
    pe_src = &a[5];
    double rc;

    rc = avarage(pb_src, pe_src);
    ck_assert_double_eq(rc, 23 / 5);
    free(pb_src);
}
END_TEST

START_TEST(tests_all_neg)
{
    int *pb_src, *pe_src;
    int a[6] = {-3, -7, -4, -5, -8, -2};
    pb_src = a;
    pe_src = &a[6];
    double rc;

    rc = avarage(pb_src, pe_src);
    ck_assert_double_eq(rc, -29 / 6);
    free(pb_src);
}
END_TEST

Suite* avarage_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("avarage");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_ava_usual);
    tcase_add_test(tc_pos, tests_float_res);
    tcase_add_test(tc_pos, tests_all_neg);
    suite_add_tcase(s, tc_pos);

    return s;
}
