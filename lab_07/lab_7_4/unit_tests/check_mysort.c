#include "../inc/check_main.h"
#include <string.h>

int compare1(const void *x1, const void *x2)
{
    char *a = (char *)x1;
    char *b = (char *)x2;
    return *a - *b;
}
int compare2(const void *x1, const void *x2)
{
    double *a = (double *)x1;
    double *b = (double *)x2;
    if ((*a - *b) > EPS)
		return 1;
	else if ((*b - *a) > EPS)
		return -1;
	else
		return 0;
}
int compare3(const void *x1, const void *x2)
{
    char *a = (char *)x1;
    char *b = (char *)x2;
    return strncmp(a, b, strlen(a));
}
START_TEST(tests_arr_one_sort)
{
    int *pa;
    int a[1] = {1};
    pa = a;

    mysort(pa, 1, sizeof(int), compare);
    ck_assert_int_eq(*pa, 1);
}
END_TEST

START_TEST(tests_usual_sort)
{
    //int *pa;
    char a[5] = "bcakf";
    //pa = a;

    mysort(a, 5, sizeof(char), compare1);
    ck_assert_int_eq(a[0], 'a');
    ck_assert_int_eq(a[1], 'b');
    ck_assert_int_eq(a[2], 'c');
    ck_assert_int_eq(a[3], 'f');
    ck_assert_int_eq(a[4], 'k');
}
END_TEST

START_TEST(tests_usual_string)
{
    //int *pa;
    char a[3][3] = {"ab", "cd", "ef"};
    //pa = a;

    mysort(a, 3, sizeof(char[3]), compare3);
    ck_assert_str_eq(a[0], "ab");
    ck_assert_str_eq(a[1], "cd");
    ck_assert_str_eq(a[2], "ef");
}
END_TEST


START_TEST(tests_neg_sort)
{
    int *pa;
    int a[5] = {-7, -5, -9, -8, -1};
    pa = a;

    mysort(pa, 5, sizeof(int), compare);
    ck_assert_int_eq(*pa, -9);
    ck_assert_int_eq(*(pa + 1), -8);
    ck_assert_int_eq(*(pa + 2), -7);
    ck_assert_int_eq(*(pa + 3), -5);
    ck_assert_int_eq(*(pa + 4), -1);
}
END_TEST

START_TEST(tests_pos_sort)
{
    int *pa;
    int a[5] = {7, 5, 9, 8, 1};
    pa = a;

    mysort(pa, 5, sizeof(int), compare);
    ck_assert_int_eq(*pa, 1);
    ck_assert_int_eq(*(pa + 1), 5);
    ck_assert_int_eq(*(pa + 2), 7);
    ck_assert_int_eq(*(pa + 3), 8);
    ck_assert_int_eq(*(pa + 4), 9);
}
END_TEST

START_TEST(tests_sortarr_sort)
{
    //double *pa;
    double a[5] = {1.8, 5, 7.858, 8.4, 9};
    //pa = a;

    mysort(a, 5, sizeof(double), compare2);
    ck_assert_double_eq_tol(a[0], 1.8, EPS);
    ck_assert_double_eq_tol(a[1], 5, EPS);
    ck_assert_double_eq_tol(a[2], 7.858, EPS);
    ck_assert_double_eq_tol(a[3], 8.4, EPS);
    ck_assert_double_eq_tol(a[4], 9,  EPS);
}
END_TEST

START_TEST(tests_null_sort)
{
    int *pa;
    int a[5] = {0, 0, 0, 0, 0};
    pa = a;

    mysort(pa, 5, sizeof(int), compare);
    ck_assert_int_eq(*pa, 0);
    ck_assert_int_eq(*(pa + 1), 0);
    ck_assert_int_eq(*(pa + 2), 0);
    ck_assert_int_eq(*(pa + 3), 0);
    ck_assert_int_eq(*(pa + 4), 0);
}
END_TEST


Suite* mysort_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("mysort");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_arr_one_sort);
    tcase_add_test(tc_pos, tests_usual_sort);
    tcase_add_test(tc_pos, tests_neg_sort);
    tcase_add_test(tc_pos, tests_pos_sort);
    tcase_add_test(tc_pos, tests_sortarr_sort);
    tcase_add_test(tc_pos, tests_null_sort);
	tcase_add_test(tc_pos, tests_usual_string);
    suite_add_tcase(s, tc_pos);

    return s;
}
