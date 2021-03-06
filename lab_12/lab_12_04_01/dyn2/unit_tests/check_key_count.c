#include "check_main.h"

typedef double (__cdecl *func_avarage)(const int *, const int *);
typedef int (__cdecl *func_key_count)(const int *, const int *, double(*func)(const int *, const int *));

static func_avarage avarage;
static func_key_count key_count;

START_TEST(tests_empty_arr)
{
    int *pb_src, *pe_src;
    int a[] = {0};
    pb_src = a;
    pe_src = a;
    int rc;

    rc = key_count(pb_src, pe_src, avarage);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_empty_keyarr)
{
    int *pb_src, *pe_src;
    int a[5] = {5, 5, 5, 5, 5};
    pb_src = a;
    pe_src = &a[5];
    int rc;

    rc = key_count(pb_src, pe_src, avarage);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_usual)
{
    int *pb_src, *pe_src;
    int a[6] = {3, 7, 4, 5, 8, 2};
    pb_src = a;
    pe_src = &a[6];
    int rc;

    rc = key_count(pb_src, pe_src, avarage);
    ck_assert_int_eq(rc, 3);
}
END_TEST

START_TEST(tests_usual2)
{
    int *pb_src, *pe_src;
    int a[6] = {-8, 4, -9, 5, -7, 1};
    pb_src = a;
    pe_src = &a[6];
    int rc;

    rc = key_count(pb_src, pe_src, avarage);
    ck_assert_int_eq(rc, 3);
}
END_TEST

START_TEST(tests_usual3)
{
    int *pb_src, *pe_src;
    int a[6] = {-3, -7, -4, -5, -8, -2};
    pb_src = a;
    pe_src = &a[6];
    int rc;

    rc = key_count(pb_src, pe_src, avarage);
    ck_assert_int_eq(rc, 3);
}
END_TEST

Suite* key_count_suite(void)
{
	HMODULE hlib = LoadLibrary("libapp.dll");
	avarage = (func_avarage)GetProcAddress(hlib, "avarage");
	key_count = (func_key_count)GetProcAddress(hlib, "key_count");
    Suite *s;
    TCase *tc_pos;

    s = suite_create("key_count");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_empty_arr);
    tcase_add_test(tc_pos, tests_empty_keyarr);
    tcase_add_test(tc_pos, tests_usual);
    tcase_add_test(tc_pos, tests_usual2);
    tcase_add_test(tc_pos, tests_usual3);
    suite_add_tcase(s, tc_pos);

	FreeLibrary(hlib);
    return s;
}


