#include "check_main.h"

typedef int (__cdecl *func_key)(const int *, int, int *, int *, double(*func)(const int *, const int *));
typedef double (__cdecl *func_avarage)(const int *, const int *);

static func_key key;
static func_avarage avarage;

START_TEST(tests_empty_arr)
{
    int *pb_src, *pb_dst = NULL, len = 0;
    int a[] = {0};
    pb_src = a;
    int rc;

    rc = key(pb_src, 0, pb_dst, &len, avarage);
    ck_assert_int_eq(len, 0);
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(tests_empty_keyarr)
{
    int *pb_src, *pb_dst = NULL, len = 0;
    int a[] = {5, 5, 5, 5, 5};
    pb_src = a;
    int rc;

    rc = key(pb_src, 5, pb_dst, &len, avarage);
    ck_assert_int_eq(len, 0);
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(tests_wrong_len)
{
    int *pb_src, *pb_dst = NULL, len = 0;
    int a[] = {5, 5, 5, 12, 10};
    pb_src = a;
    int rc;

    rc = key(pb_src, 5, pb_dst, &len, avarage);
    ck_assert_int_eq(len, 2);
    ck_assert_int_eq(rc, MY_ERROR);
}
END_TEST

START_TEST(tests_wrong_len2)
{
    int *pb_src, *pb_dst = NULL, len = 0;
    int a[] = {5, 5, 5, 12, 5};
    pb_src = a;
    int rc;

    rc = key(pb_src, 5, pb_dst, &len, avarage);
    ck_assert_int_eq(len, 1);
    ck_assert_int_eq(rc, MY_ERROR);
}
END_TEST


START_TEST(test_key_usual)
{
    int *pb_src, *pb_dst, len = 3;
    int a[] = {5, 5, 15, 48, 12, 5};
    int b[3];
    pb_dst = b;
    pb_src = a;
    int rc;

    rc = key(pb_src, 6, pb_dst, &len, avarage);
    ck_assert_int_eq(len, 3);
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_key_usual2)
{
    int *pb_src, *pb_dst, len = 5;
    int a[] = {5, -5, 15, -48, 12, 5};
    int b[5];
    pb_dst = b;
    pb_src = a;
    int rc;

    rc = key(pb_src, 6, pb_dst, &len, avarage);
    ck_assert_int_eq(len, 5);
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_keyarr_one)
{
    int *pb_src, *pb_dst, len = 1;
    int a[] = {5, 5, 5, 12, 5};
    int b[1];
    pb_dst = b;
    pb_src = a;
    int rc;

    rc = key(pb_src, 5, pb_dst, &len, avarage);
    ck_assert_int_eq(len, 1);
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_keyarr_neg)
{
    int *pb_src, *pb_dst, len = 4;
    int a[] = {-9, -7, -52, 0, -1};
    int b[4];
    pb_dst = b;
    pb_src = a;
    int rc;

    rc = key(pb_src, 5, pb_dst, &len, avarage);
    ck_assert_int_eq(len, 4);
    ck_assert_int_eq(rc, OK);
}
END_TEST

Suite* key_suite(void)
{
	HMODULE hlib = LoadLibrary("libapp.dll");
	avarage = (func_avarage)GetProcAddress(hlib, "avarage");
	key = (func_key)GetProcAddress(hlib, "key");
	
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("key");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, tests_empty_arr);
    tcase_add_test(tc_neg, tests_empty_keyarr);
    tcase_add_test(tc_neg, tests_wrong_len);
    tcase_add_test(tc_neg, tests_wrong_len2);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_key_usual);
    tcase_add_test(tc_pos, test_key_usual2);
    tcase_add_test(tc_pos, test_keyarr_one);
    tcase_add_test(tc_pos, test_keyarr_neg);
    suite_add_tcase(s, tc_pos);

	FreeLibrary(hlib);
    return s;
}
