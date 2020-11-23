#include "check_main.h"

START_TEST(tests_input_out)
{
    FILE *f;
    char str[LENCOMMAND];
    f = fopen("unit_tests/f4.txt", "r");
    if (f)
    {
        int rc = inputcommand(f, str);
        ck_assert_int_eq(rc, OK);
        ck_assert_str_eq(str, "out");
        fclose(f);
    }
}
END_TEST

START_TEST(tests_input_cat)
{
    FILE *f;
    char str[LENCOMMAND];
    f = fopen("unit_tests/f5.txt", "r");
    if (f)
    {
        int rc = inputcommand(f, str);
        ck_assert_int_eq(rc, OK);
        ck_assert_str_eq(str, "cat");
        fclose(f);
    }
}
END_TEST

START_TEST(tests_input_sps)
{
    FILE *f;
    char str[LENCOMMAND];
    f = fopen("unit_tests/f6.txt", "r");
    if (f)
    {
        int rc = inputcommand(f, str);
        ck_assert_int_eq(rc, OK);
        ck_assert_str_eq(str, "sps");
        fclose(f);
    }
}
END_TEST

START_TEST(tests_input_pos)
{
    FILE *f;
    char str[LENCOMMAND];
    f = fopen("unit_tests/f7.txt", "r");
    if (f)
    {
        int rc = inputcommand(f, str);
        ck_assert_int_eq(rc, OK);
        ck_assert_str_eq(str, "pos");
        fclose(f);
    }
}
END_TEST

START_TEST(tests_input_none)
{
    FILE *f;
    char str[LENCOMMAND];
    f = fopen("unit_tests/f3.txt", "r");
    if (f)
    {
        int rc = inputcommand(f, str);
        ck_assert_int_eq(rc, COMMANDERROR);
        fclose(f);
    }
}
END_TEST

START_TEST(tests_input_error)
{
    FILE *f;
    char str[LENCOMMAND];
    f = fopen("unit_tests/f8.txt", "r");
    if (f)
    {
        int rc = inputcommand(f, str);
        ck_assert_int_eq(rc, COMMANDERROR);
        ck_assert_str_eq(str, "qwee");
        fclose(f);
    }
}
END_TEST

START_TEST(tests_input_error1)
{
    FILE *f;
    char str[LENCOMMAND];
    f = fopen("unit_tests/f1.txt", "r");
    if (f)
    {
        int rc = inputcommand(f, str);
        ck_assert_int_eq(rc, COMMANDERROR);
        ck_assert_str_eq(str, "I love C");
        fclose(f);
    }
}
END_TEST

START_TEST(tests_input_error2)
{
    FILE *f;
    char str[LENCOMMAND];
    f = fopen("unit_tests/f2.txt", "r");
    if (f)
    {
        int rc = inputcommand(f, str);
        ck_assert_int_eq(rc, COMMANDERROR);
        ck_assert_str_eq(str, "s");
        fclose(f);
    }
}
END_TEST


Suite* inputcommand_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("inputcommand");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_input_out);
    tcase_add_test(tc_pos, tests_input_cat);
    tcase_add_test(tc_pos, tests_input_sps);
    tcase_add_test(tc_pos, tests_input_pos);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, tests_input_none);
    tcase_add_test(tc_neg, tests_input_error);
    tcase_add_test(tc_neg, tests_input_error1);
    tcase_add_test(tc_neg, tests_input_error2);
    suite_add_tcase(s, tc_neg);

    return s;
}
