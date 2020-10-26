#include "check_main.h"

START_TEST(tests_usual)
{
    FILE *f = fopen("func_tests/f1.txt","r");
    int rc, n;

    if (f)
    {
        rc = f_count(f, &n);
        ck_assert_int_eq(rc, OK);
        ck_assert_int_eq(n, 1);
        fclose(f);
    }
}
END_TEST

START_TEST(tests_usual_more)
{
    FILE *f = fopen("func_tests/f5.txt","r");
    int rc, n;

    if (f)
    {
        rc = f_count(f, &n);
        ck_assert_int_eq(rc, OK);
        ck_assert_int_eq(n, 4);
        fclose(f);
    }
}
END_TEST

START_TEST(tests_empty_name)
{
    FILE *f = fopen("func_tests/f2.txt","r");
    int rc, n;

    if (f)
    {
        rc = f_count(f, &n);
        ck_assert_int_eq(rc, OK);
        ck_assert_int_eq(n, 1);
        fclose(f);
    }
}
END_TEST

START_TEST(tests_empty_title)
{
    FILE *f = fopen("func_tests/f3.txt","r");
    int rc, n;

    if (f)
    {
        rc = f_count(f, &n);
        ck_assert_int_eq(rc, OK);
        ck_assert_int_eq(n, 1);
        fclose(f);
    }
}
END_TEST

START_TEST(tests_let_year)
{
    FILE *f = fopen("func_tests/f4.txt","r");
    int rc, n;

    if (f)
    {
        rc = f_count(f, &n);
        ck_assert_int_eq(rc, FILE_INVALID_ARG);
        ck_assert_int_eq(n, 0);
        fclose(f);
    }
}
END_TEST

Suite* f_count_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("f_count");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, tests_let_year);
    tcase_add_test(tc_neg, tests_empty_title);
    tcase_add_test(tc_neg, tests_empty_name);
    suite_add_tcase(s, tc_neg);


    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_usual);
    tcase_add_test(tc_pos, tests_usual_more);
    suite_add_tcase(s, tc_pos);

    return s;
}
