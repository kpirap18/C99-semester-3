#include "../inc/check_main.h"

START_TEST(tests_arr_one_sort)
{
    int *pa;
    int a[1] = {1};
    pa = a;

    mysort(pa, 1, sizeof(int), compare);
    ck_assert_int_eq(*pa, 1);
}
END_TEST

START_TEST(tests_usual_sort)
{
    int *pa;
    int a[5] = {7, 5, 9, -8, 0};
    pa = a;

    mysort(pa, 5, sizeof(int), compare);
    ck_assert_int_eq(*pa, -8);
    ck_assert_int_eq(*(pa + 1), 0);
    ck_assert_int_eq(*(pa + 2), 5);
    ck_assert_int_eq(*(pa + 3), 7);
    ck_assert_int_eq(*(pa + 4), 9);
}
END_TEST

START_TEST(tests_neg_sort)
{
    int *pa;
    int a[5] = {-7, -5, -9, -8, -1};
    pa = a;

    mysort(pa, 5, sizeof(int), compare);
    ck_assert_int_eq(*pa, -9);
    ck_assert_int_eq(*(pa + 1), -8);
    ck_assert_int_eq(*(pa + 2), -7);
    ck_assert_int_eq(*(pa + 3), -5);
    ck_assert_int_eq(*(pa + 4), -1);
}
END_TEST

START_TEST(tests_pos_sort)
{
    int *pa;
    int a[5] = {7, 5, 9, 8, 1};
    pa = a;

    mysort(pa, 5, sizeof(int), compare);
    ck_assert_int_eq(*pa, 1);
    ck_assert_int_eq(*(pa + 1), 5);
    ck_assert_int_eq(*(pa + 2), 7);
    ck_assert_int_eq(*(pa + 3), 8);
    ck_assert_int_eq(*(pa + 4), 9);
}
END_TEST

START_TEST(tests_sortarr_sort)
{
    int *pa;
    int a[5] = {1, 5, 7, 8, 9};
    pa = a;

    mysort(pa, 5, sizeof(int), compare);
    ck_assert_int_eq(*pa, 1);
    ck_assert_int_eq(*(pa + 1), 5);
    ck_assert_int_eq(*(pa + 2), 7);
    ck_assert_int_eq(*(pa + 3), 8);
    ck_assert_int_eq(*(pa + 4), 9);
}
END_TEST

START_TEST(tests_null_sort)
{
    int *pa;
    int a[5] = {0, 0, 0, 0, 0};
    pa = a;

    mysort(pa, 5, sizeof(int), compare);
    ck_assert_int_eq(*pa, 0);
    ck_assert_int_eq(*(pa + 1), 0);
    ck_assert_int_eq(*(pa + 2), 0);
    ck_assert_int_eq(*(pa + 3), 0);
    ck_assert_int_eq(*(pa + 4), 0);
}
END_TEST

Suite* mysort_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("mysort");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_arr_one_sort);
    tcase_add_test(tc_pos, tests_usual_sort);
    tcase_add_test(tc_pos, tests_neg_sort);
    tcase_add_test(tc_pos, tests_pos_sort);
    tcase_add_test(tc_pos, tests_sortarr_sort);
    tcase_add_test(tc_pos, tests_null_sort);
    suite_add_tcase(s, tc_pos);

    return s;
}
