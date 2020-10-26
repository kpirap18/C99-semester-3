#include "check_main.h"

START_TEST(tests_name)
{
    int rc;

    rc = my_check_feild("name");
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(tests_title)
{
    int rc;

    rc = my_check_feild("title");
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(tests_year)
{
    int rc;

    rc = my_check_feild("year");
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(tests_error)
{
    int rc;

    rc = my_check_feild("years");
    ck_assert_int_eq(rc, INVALID_ARG);
}
END_TEST


Suite* my_check_feild_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("my_check_feild");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, tests_error);
    suite_add_tcase(s, tc_neg);


    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_name);
    tcase_add_test(tc_pos, tests_title);
    tcase_add_test(tc_pos, tests_year);
    suite_add_tcase(s, tc_pos);

    return s;
}
