#include "check_main.h"

START_TEST(tests_checkfile_none)
{
    int rc = checkfile("none.txt");
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

START_TEST(tests_checkfile_empty)
{
    int rc = checkfile("empty.txt");
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

START_TEST(tests_checkfile_opener)
{
    int rc = checkfile("err");
    ck_assert_int_eq(rc, ERROR);
}
END_TEST

START_TEST(tests_checkfile_one)
{
    int rc = checkfile("one.c");
    ck_assert_int_eq(rc, 1);
    FILE *f = fopen("one.c", "rb");
    int words = wordinfile(f, rc);
    ck_assert_int_eq(words, 1); 
    fclose(f);
}
END_TEST

START_TEST(tests_checkfile_usual)
{
    int rc = checkfile("tests.c");
    ck_assert_int_eq(rc, 63);
    FILE *f = fopen("tests.c", "rb");
    int words = wordinfile(f, rc);
    ck_assert_int_eq(words, 8); 
    fclose(f);
}
END_TEST

Suite* checkfile_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("checkfile");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_checkfile_none);
    tcase_add_test(tc_pos, tests_checkfile_empty);
    tcase_add_test(tc_pos, tests_checkfile_opener);
    tcase_add_test(tc_pos, tests_checkfile_usual);
    tcase_add_test(tc_pos, tests_checkfile_one);
    suite_add_tcase(s, tc_pos);

    return s;
}