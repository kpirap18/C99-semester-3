#include "check_main.h"

START_TEST(tests_empty_arr)
{
    int *pb_src, *pe_src;
    int a[] = {0};
    pb_src = a;
    pe_src = a;
    int rc;

    rc = key_count(pb_src, pe_src, avarage);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_empty_keyarr)
{
    int *pb_src, *pe_src;
    int a[5] = {5, 5, 5, 5, 5};
    pb_src = a;
    pe_src = &a[5];
    int rc;

    rc = key_count(pb_src, pe_src, avarage);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_usual)
{
    int *pb_src, *pe_src;
    int a[6] = {3, 7, 4, 5, 8, 2};
    pb_src = a;
    pe_src = &a[6];
    int rc;

    rc = key_count(pb_src, pe_src, avarage);
    ck_assert_int_eq(rc, 3);
}
END_TEST

Suite* key_count_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("key_count");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_empty_arr);
    tcase_add_test(tc_pos, tests_empty_keyarr);
    tcase_add_test(tc_pos, tests_usual);
    suite_add_tcase(s, tc_pos);

    return s;
}


