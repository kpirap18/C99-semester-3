#include "check_main.h"

START_TEST(tests_isdelim_is1)
{
    int is = isdelim(' ');
    ck_assert_int_eq(is, 1);
}
END_TEST

START_TEST(tests_isdelim_is2)
{
    int is = isdelim('.');
    ck_assert_int_eq(is, 1);
}
END_TEST

START_TEST(tests_isdelim_is3)
{
    int is = isdelim('\\');
    ck_assert_int_eq(is, 1);
}
END_TEST

START_TEST(tests_isdelim_is4)
{
    int is = isdelim('\n');
    ck_assert_int_eq(is, 1);
}
END_TEST

START_TEST(tests_isdelim_is5)
{
    int is = isdelim('\"');
    ck_assert_int_eq(is, 1);
}
END_TEST

START_TEST(tests_isdelim_is6)
{
    int is = isdelim('\'');
    ck_assert_int_eq(is, 1);
}
END_TEST

START_TEST(tests_isdelim_isnt1)
{
    int is = isdelim('a');
    ck_assert_int_eq(is, 0);
}
END_TEST

START_TEST(tests_isdelim_isnt2)
{
    int is = isdelim('q');
    ck_assert_int_eq(is, 0);
}
END_TEST

Suite* isdelim_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("isdelim");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_isdelim_is1);
    tcase_add_test(tc_pos, tests_isdelim_is2);
    tcase_add_test(tc_pos, tests_isdelim_is3);
    tcase_add_test(tc_pos, tests_isdelim_is4);
    tcase_add_test(tc_pos, tests_isdelim_is5);
    tcase_add_test(tc_pos, tests_isdelim_is6);
    tcase_add_test(tc_pos, tests_isdelim_isnt1);
    tcase_add_test(tc_pos, tests_isdelim_isnt2);
    suite_add_tcase(s, tc_pos);

    return s;
}
