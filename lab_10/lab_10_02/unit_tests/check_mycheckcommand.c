#include "check_main.h"

START_TEST(tests_check_out)
{
    int rc = mycheckcommand("out");
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(tests_check_cat)
{
    int rc = mycheckcommand("cat");
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(tests_check_sps)
{
    int rc = mycheckcommand("sps");
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(tests_check_pos)
{
    int rc = mycheckcommand("pos");
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(tests_check_error1)
{
    int rc = mycheckcommand("pos1");
    ck_assert_int_eq(rc, COMMANDERROR);
}
END_TEST

START_TEST(tests_check_error2)
{
    int rc = mycheckcommand("d");
    ck_assert_int_eq(rc, COMMANDERROR);
}
END_TEST

START_TEST(tests_check_error3)
{
    int rc = mycheckcommand("egrt");
    ck_assert_int_eq(rc, COMMANDERROR);
}
END_TEST

START_TEST(tests_check_error4)
{
    int rc = mycheckcommand("p111");
    ck_assert_int_eq(rc, COMMANDERROR);
}
END_TEST

START_TEST(tests_check_error5)
{
    int rc = mycheckcommand(" ");
    ck_assert_int_eq(rc, COMMANDERROR);
}
END_TEST

START_TEST(tests_check_error6)
{
    int rc = mycheckcommand("");
    ck_assert_int_eq(rc, COMMANDERROR);
}
END_TEST

Suite* mycheckcommand_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("mycheckcommand");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, tests_check_error1);
	tcase_add_test(tc_neg, tests_check_error2);
    tcase_add_test(tc_neg, tests_check_error3);
    tcase_add_test(tc_neg, tests_check_error4);
    tcase_add_test(tc_neg, tests_check_error5);
    tcase_add_test(tc_neg, tests_check_error6);
    suite_add_tcase(s, tc_neg);


    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_check_out);
    tcase_add_test(tc_pos, tests_check_cat);
    tcase_add_test(tc_pos, tests_check_sps);
    tcase_add_test(tc_pos, tests_check_pos);
    suite_add_tcase(s, tc_pos);

    return s;
}
