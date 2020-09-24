#include "../inc/check_main.h"

START_TEST(tests_file_usual)
{
    FILE *f = fopen("1.txt", "r");
    int rc;

    rc = file_size(f);
    ck_assert_int_eq(rc, 5);
}
END_TEST

START_TEST(tests_file_similar)
{
    FILE *f = fopen("2.txt", "r");
    int rc;

    rc = file_size(f);
    ck_assert_int_eq(rc, 4);
}
END_TEST

START_TEST(tests_file_one)
{
    FILE *f = fopen("3.txt", "r");
    int rc;

    rc = file_size(f);
    ck_assert_int_eq(rc, 1);
}
END_TEST

START_TEST(tests_file_empty)
{
    FILE *f = fopen("4.txt", "r");
    int rc;

    rc = file_size(f);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_file_float)
{
    FILE *f = fopen("5.txt", "r");
    int rc;

    rc = file_size(f);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_file_let)
{
    FILE *f = fopen("6.txt", "r");
    int rc;

    rc = file_size(f);
    ck_assert_int_eq(rc, 0);
}
END_TEST

Suite* file_size_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("file_size");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, tests_file_empty);
    tcase_add_test(tc_neg, tests_file_float);
    tcase_add_test(tc_neg, tests_file_let);
    suite_add_tcase(s, tc_neg);


    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_file_usual);
    tcase_add_test(tc_pos, tests_file_similar);
    tcase_add_test(tc_pos, tests_file_one);
    suite_add_tcase(s, tc_pos);

    return s;
}
