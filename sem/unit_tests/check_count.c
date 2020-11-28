#include "check_main.h"

START_TEST(tests_count_one)
{
    int all = count("tests.c");
    ck_assert_int_eq(all, 8);
}
END_TEST

START_TEST(tests_count_two)
{
    int all = count("tests.c", "a");
    ck_assert_int_eq(all, 12);
}
END_TEST

START_TEST(tests_count_more1)
{
    int all = count("tests.c", "a", "tests.txt");
    ck_assert_int_eq(all, 19);
}
END_TEST

START_TEST(tests_count_more2)
{
    int all = count("tests.c", "a", "tests.txt", "makefile");
    ck_assert_int_eq(all, 172);
}
END_TEST

START_TEST(tests_count_none)
{
    int all = count("none.txt");
    ck_assert_int_eq(all, 0);
}
END_TEST

START_TEST(tests_count_txt)
{
    int all = count("tests.txt");
    ck_assert_int_eq(all, 7);
}
END_TEST

START_TEST(tests_count_h)
{
    int all = count("inc/count.h");
    ck_assert_int_eq(all, 19);
}
END_TEST

Suite* count_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("count");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_count_one);
	tcase_add_test(tc_pos, tests_count_two);
    tcase_add_test(tc_pos, tests_count_none);
    tcase_add_test(tc_pos, tests_count_txt);
    tcase_add_test(tc_pos, tests_count_h);
    tcase_add_test(tc_pos, tests_count_more1);
    tcase_add_test(tc_pos, tests_count_more2);
    suite_add_tcase(s, tc_pos);

    return s;
}
