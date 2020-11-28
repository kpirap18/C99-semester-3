#include "check_main.h"

START_TEST(tests_compar_int_less)
{
    int a = 2, b = 3;
    int *aa = &a, *bb = &b;
    int rc;

    rc = comparator_int(aa, bb);
    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(tests_compar_int_null)
{
    int a = 3, b = 3;
    int *aa = &a, *bb = &b;
    int rc;

    rc = comparator_int(aa, bb);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_compar_int_bigger)
{
    int a = 4, b = 3;
    int *aa = &a, *bb = &b;
    int rc;

    rc = comparator_int(aa, bb);
    ck_assert_int_eq(rc, 1);
}
END_TEST

START_TEST(tests_compar_char_less)
{
    char a = 'a', b = 'z';
    char *aa = &a, *bb = &b;
    int rc;

    rc = comparator_char(aa, bb);
    ck_assert_int_eq(rc, -25);
}
END_TEST

START_TEST(tests_compar_char_null)
{
    char a = 'b', b = 'b';
    char *aa = &a, *bb = &b;
    int rc;

    rc = comparator_char(aa, bb);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_compar_char_bigger)
{
    char a = 'x', b = 'c';
    char *aa = &a, *bb = &b;
    int rc;

    rc = comparator_char(aa, bb);
    ck_assert_int_eq(rc, 21);
}
END_TEST

START_TEST(tests_compar_double_less)
{
    double a = 2.45, b = 3.5;
    double *aa = &a, *bb = &b;
    int rc;

    rc = comparator_double(aa, bb);
    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(tests_compar_double_null)
{
    double a = 3.32, b = 3.32;
    double *aa = &a, *bb = &b;
    int rc;

    rc = comparator_double(aa, bb);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_compar_double_bigger)
{
    double a = 4.34, b = 3.45;
    double *aa = &a, *bb = &b;
    int rc;

    rc = comparator_double(aa, bb);
    ck_assert_int_eq(rc, 1);
}
END_TEST


START_TEST(tests_compar_book_less)
{
    book_r a = { "AAd", "www" };
    book_r b = { "AAf", "www" };
    book_r *aa = &a, *bb = &b;
    int rc;

    rc = comparator_book(aa, bb);
    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(tests_compar_book_null)
{
    book_r a = { "qqq", "www" };
    book_r b = { "qqq", "ww1" };
    book_r *aa = &a, *bb = &b;
    int rc;

    rc = comparator_book(aa, bb);
    ck_assert_int_eq(rc, 1);
}
END_TEST

START_TEST(tests_compar_book_bigger)
{
    book_r a = { "AAA", "qqq" };
    book_r b = { "AAA", "qqq" };
    book_r *aa = &a, *bb = &b;
    int rc;

    rc = comparator_book(aa, bb);
    ck_assert_int_eq(rc, 0);
}
END_TEST

Suite* comparator_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("comparator");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_compar_int_less);
    tcase_add_test(tc_pos, tests_compar_int_null);
    tcase_add_test(tc_pos, tests_compar_int_bigger);
    tcase_add_test(tc_pos, tests_compar_char_less);
    tcase_add_test(tc_pos, tests_compar_char_null);
    tcase_add_test(tc_pos, tests_compar_char_bigger);
    tcase_add_test(tc_pos, tests_compar_double_less);
    tcase_add_test(tc_pos, tests_compar_double_null);
    tcase_add_test(tc_pos, tests_compar_double_bigger);
    tcase_add_test(tc_pos, tests_compar_book_less);
    tcase_add_test(tc_pos, tests_compar_book_null);
    tcase_add_test(tc_pos, tests_compar_book_bigger);
    suite_add_tcase(s, tc_pos);

    return s;
}