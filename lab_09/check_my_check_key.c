#include "check_main.h"

START_TEST(tests_usual)
{
    int rc;

    rc = my_check_key("1234");
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(tests_error)
{
    int rc;

    rc = my_check_feild("t");
    ck_assert_int_eq(rc, OK);
}
END_TEST



Suite* my_check_key_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("me_check_key");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, tests_error);
    suite_add_tcase(s, tc_neg);


    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_usual);
    suite_add_tcase(s, tc_pos);

    return s;
}
