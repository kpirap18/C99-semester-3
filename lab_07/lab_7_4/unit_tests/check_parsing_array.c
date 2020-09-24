#include "../inc/check_main.h"

START_TEST(tests_file_usual)
{
    FILE *f = fopen("1.txt", "r");
    int a[5];
    int *pa = a;

    parsing_array(f, pa);
    ck_assert_int_eq(*pa, 4);
    ck_assert_int_eq(*(pa + 1), 7);
    ck_assert_int_eq(*(pa + 2), -8);
    ck_assert_int_eq(*(pa + 3), 5);
    ck_assert_int_eq(*(pa + 4), 6);
}
END_TEST

START_TEST(tests_file_similar)
{
    FILE *f = fopen("2.txt", "r");
    int a[4];
    int *pa = a;

    parsing_array(f, pa);
    ck_assert_int_eq(*pa, 1);
    ck_assert_int_eq(*(pa + 1), 1);
    ck_assert_int_eq(*(pa + 2), 1);
    ck_assert_int_eq(*(pa + 3), 1);
}
END_TEST

START_TEST(tests_file_one)
{
    FILE *f = fopen("3.txt", "r");
    int a[1];
    int *pa = a;

    parsing_array(f, pa);
    ck_assert_int_eq(*pa, 8);
}
END_TEST


Suite* parsing_array_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("parsing_array");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_file_usual);
    tcase_add_test(tc_pos, tests_file_similar);
    tcase_add_test(tc_pos, tests_file_one);
    suite_add_tcase(s, tc_pos);

    return s;
}
