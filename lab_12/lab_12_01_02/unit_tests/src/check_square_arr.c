#include "check_main.h"

START_TEST(tests_square_arr1)
{
    int a[6] = {1, 2, 3, 4, 5, 6};
	int b[2];
	int len_b = 2;

    int rc = square_arr(a, 6, b, &len_b);
    ck_assert_int_eq(rc, 0);
	ck_assert_int_eq(b[0], 1);
	ck_assert_int_eq(b[1], 4);
}
END_TEST

START_TEST(tests_square_arr2)
{
    int a[6] = {1, 2, 3, 4, 5, 0};
	int b[3];
	int len_b = 3;

    int rc = square_arr(a, 6, b, &len_b);
    ck_assert_int_eq(rc, 0);
	ck_assert_int_eq(b[0], 1);
	ck_assert_int_eq(b[1], 4);
	ck_assert_int_eq(b[2], 0);
}
END_TEST

START_TEST(tests_square_arr3)
{
    int a[6] = {1, -1, -9, 4, 5, 0};
	int b[3];
	int len_b = 3;

    int rc = square_arr(a, 6, b, &len_b);
    ck_assert_int_eq(rc, 0);
	ck_assert_int_eq(b[0], 1);
	ck_assert_int_eq(b[1], 4);
	ck_assert_int_eq(b[2], 0);
}
END_TEST

START_TEST(tests_square_arr4)
{
    int a[6] = {16, -1, -9, 4, 25, 0};
	int b[4];
	int len_b = 4;

    int rc = square_arr(a, 6, b, &len_b);
    ck_assert_int_eq(rc, 0);
	ck_assert_int_eq(b[0], 16);
	ck_assert_int_eq(b[1], 4);
	ck_assert_int_eq(b[2], 25);
	ck_assert_int_eq(b[3], 0);
}
END_TEST

START_TEST(tests_square_arr01)
{
    int a[6] = {21, 5, 6, 8, 7, 3};
	int b[1];
	int len_b = 0;

    int rc = square_arr(a, 6, b, &len_b);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_square_arr02)
{
    int a[6] = {16, -1, -9, 4, 25, 0};
	int b[4];
	int len_b = 2;

    int rc = square_arr(a, 6, b, &len_b);
    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(tests_square_arr03)
{
    int a[6] = {16, -1, -9, 4, 25, 0};
	int b[4];
	int len_b = -9;

    int rc = square_arr(a, 6, b, &len_b);
    ck_assert_int_eq(rc, -1);
}
END_TEST

Suite* square_arr_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("square_arr");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, tests_square_arr01);
    tcase_add_test(tc_neg, tests_square_arr02);
    tcase_add_test(tc_neg, tests_square_arr03);
    suite_add_tcase(s, tc_neg);


    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_square_arr1);
    tcase_add_test(tc_pos, tests_square_arr2);
    tcase_add_test(tc_pos, tests_square_arr3);
	tcase_add_test(tc_pos, tests_square_arr4);
    suite_add_tcase(s, tc_pos);

    return s;
}
