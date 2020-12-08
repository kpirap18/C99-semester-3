#include "check_main.h"

typedef int (__cdecl *func_comparator_int)(const void *, const void *);

static func_comparator_int comparator_int;

START_TEST(tests_compare_less)
{
    int a = 2, b = 3;
    int *aa = &a, *bb = &b;
    int rc;

    rc = comparator_int(aa, bb);
    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(tests_compare_null)
{
    int a = 3, b = 3;
    int *aa = &a, *bb = &b;
    int rc;

    rc = comparator_int(aa, bb);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_compare_bigger)
{
    int a = 4, b = 3;
    int *aa = &a, *bb = &b;
    int rc;

    rc = comparator_int(aa, bb);
    ck_assert_int_eq(rc, 1);
}
END_TEST

START_TEST(tests_compare_less2)
{
    int a = -2, b = -3;
    int *aa = &a, *bb = &b;
    int rc;

    rc = comparator_int(aa, bb);
    ck_assert_int_eq(rc, 1);
}
END_TEST

START_TEST(tests_compare_null2)
{
    int a = -3, b = -3;
    int *aa = &a, *bb = &b;
    int rc;

    rc = comparator_int(aa, bb);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_compare_bigger2)
{
    int a = -4, b = -3;
    int *aa = &a, *bb = &b;
    int rc;

    rc = comparator_int(aa, bb);
    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(tests_compare_nul)
{
    int a = 0, b = 0;
    int *aa = &a, *bb = &b;
    int rc;

    rc = comparator_int(aa, bb);
    ck_assert_int_eq(rc, 0);
}
END_TEST

Suite* compare_suite(void)
{
	HMODULE hlib = LoadLibrary("libapp.dll");
	comparator_int = (func_comparator_int)GetProcAddress(hlib, "comparator_int");
	
    Suite *s;
    TCase *tc_pos;

    s = suite_create("compare");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_compare_less);
    tcase_add_test(tc_pos, tests_compare_null);
    tcase_add_test(tc_pos, tests_compare_bigger);
    tcase_add_test(tc_pos, tests_compare_less2);
    tcase_add_test(tc_pos, tests_compare_null2);
    tcase_add_test(tc_pos, tests_compare_bigger2);
    tcase_add_test(tc_pos, tests_compare_nul);
    suite_add_tcase(s, tc_pos);

	FreeLibrary(hlib);
    return s;
}
