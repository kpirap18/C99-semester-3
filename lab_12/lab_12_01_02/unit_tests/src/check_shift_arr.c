#include "check_main.h"

START_TEST(tests_shift_usual1)
{
    int a[6] = {1, 2, 3, 4, 5, 6};

    shift_arr(a, 6, 2);
    ck_assert_int_eq(a[0], 3);
	ck_assert_int_eq(a[1], 4);
	ck_assert_int_eq(a[2], 5);
	ck_assert_int_eq(a[3], 6);
	ck_assert_int_eq(a[4], 1);
	ck_assert_int_eq(a[5], 2);
}
END_TEST

START_TEST(tests_shift_usual2)
{
    int a[6] = {-1, 2, 3, -4, 5, 6};

    shift_arr(a, 6, 2);
    ck_assert_int_eq(a[0], 3);
	ck_assert_int_eq(a[1], -4);
	ck_assert_int_eq(a[2], 5);
	ck_assert_int_eq(a[3], 6);
	ck_assert_int_eq(a[4], -1);
	ck_assert_int_eq(a[5], 2);
}
END_TEST

START_TEST(tests_shift_usual3)
{
    int a[6] = {-1, 0, 3, -4, 0, 6};

    shift_arr(a, 6, 2);
    ck_assert_int_eq(a[0], 3);
	ck_assert_int_eq(a[1], -4);
	ck_assert_int_eq(a[2], 0);
	ck_assert_int_eq(a[3], 6);
	ck_assert_int_eq(a[4], -1);
	ck_assert_int_eq(a[5], 0);
}
END_TEST

START_TEST(tests_shift_to0)
{
    int a[6] = {-1, 0, 3, -4, 0, 6};

    shift_arr(a, 6, 0);
    ck_assert_int_eq(a[0], -1);
	ck_assert_int_eq(a[1], 0);
	ck_assert_int_eq(a[2], 3);
	ck_assert_int_eq(a[3], -4);
	ck_assert_int_eq(a[4], 0);
	ck_assert_int_eq(a[5], 6);
}
END_TEST

START_TEST(tests_shift_tomore)
{
    int a[6] = {-1, 0, 3, -4, 0, 6};

    shift_arr(a, 6, 13);
    ck_assert_int_eq(a[0], 0);
	ck_assert_int_eq(a[1], 3);
	ck_assert_int_eq(a[2], -4);
	ck_assert_int_eq(a[3], 0);
	ck_assert_int_eq(a[4], 6);
	ck_assert_int_eq(a[5], -1);
}
END_TEST

START_TEST(tests_shift_tolen)
{
    int a[6] = {-1, 0, 3, -4, 0, 6};

    shift_arr(a, 6, 6);
    ck_assert_int_eq(a[0], -1);
	ck_assert_int_eq(a[1], 0);
	ck_assert_int_eq(a[2], 3);
	ck_assert_int_eq(a[3], -4);
	ck_assert_int_eq(a[4], 0);
	ck_assert_int_eq(a[5], 6);
}
END_TEST

Suite* shift_arr_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("shift_arr");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_shift_usual1);
	tcase_add_test(tc_pos, tests_shift_usual2);
	tcase_add_test(tc_pos, tests_shift_usual3);
	tcase_add_test(tc_pos, tests_shift_to0);
	tcase_add_test(tc_pos, tests_shift_tomore);
	tcase_add_test(tc_pos, tests_shift_tolen);
    suite_add_tcase(s, tc_pos);

    return s;
}

