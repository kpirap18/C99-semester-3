#include "check_main.h"

START_TEST(tests_is_square1)
{
    int a = 25;
    int rc = is_square(a);
    ck_assert_int_eq(rc, 1);
}
END_TEST

START_TEST(tests_is_square2)
{
    int a = 1;
    int rc = is_square(a);
    ck_assert_int_eq(rc, 1);
}
END_TEST

START_TEST(tests_is_square3)
{
    int a = 0;
    int rc = is_square(a);
    ck_assert_int_eq(rc, 1);
}
END_TEST

START_TEST(tests_is_square4)
{
    int a = 4;
    int rc = is_square(a);
    ck_assert_int_eq(rc, 1);
}
END_TEST

START_TEST(tests_is_square01)
{
    int a = 2;
    int rc = is_square(a);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_is_square02)
{
    int a = -1;
    int rc = is_square(a);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_is_square03)
{
    int a = -9;
    int rc = is_square(a);
    ck_assert_int_eq(rc, 0);
}
END_TEST

Suite* is_square_suite(void)
{
    Suite *s;
    TCase *tc_pos;
	TCase *tc_neg;

    s = suite_create("is_square");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_is_square1);
	tcase_add_test(tc_pos, tests_is_square2);
	tcase_add_test(tc_pos, tests_is_square3);
	tcase_add_test(tc_pos, tests_is_square4);
    suite_add_tcase(s, tc_pos);
	
	tc_neg = tcase_create("negatives");
    tcase_add_test(tc_pos, tests_is_square01);
	tcase_add_test(tc_pos, tests_is_square02);
	tcase_add_test(tc_pos, tests_is_square03);
    suite_add_tcase(s, tc_neg);

    return s;
}
