#include "../inc/check_main.h"

START_TEST(tests_empty_arr)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int a[] = {0};
    pb_src = a;
    pe_src = a;
    int rc;

    rc = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, KEYARRAY_EMRTY_ERR);
    ck_assert_ptr_null(pb_dst);
}
END_TEST

START_TEST(tests_empty_keyarr)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int a[5] = {5, 5, 5, 5, 5};
    pb_src = a;
    pe_src = &a[5];
    int rc;

    rc = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, KEYARRAY_EMRTY_ERR);
    ck_assert_ptr_null(pb_dst);
}
END_TEST

START_TEST(test_key_wrong_ptrs_not)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int a = 1, b = 2;
    pb_src = &a;
    pe_src = &b;
    int rc;

    rc = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, KEYARRAY_EMRTY_ERR);
    ck_assert_ptr_null(pb_dst);
}
END_TEST




START_TEST(test_key_usual)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int a[6] = {3, 3, 1, 10, 5, 5};
    pb_src = a;
    pe_src = &a[6];
    int rc;

    rc = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, 3);
    ck_assert_ptr_nonnull(pb_dst);
    ck_assert_int_eq(*pb_dst, 10);
    ck_assert_int_eq(*(pe_dst - 1), 5);
    ck_assert_int_eq((pe_dst - pb_dst), 3);
	free(pb_dst);
}
END_TEST

START_TEST(test_keyarr_one)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int a[6] = {3, 3, 1, 10, 2, 2};
    pb_src = a;
    pe_src = &a[6];
    int rc;

    rc = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, 1);
    ck_assert_ptr_nonnull(pb_dst);
    ck_assert_int_eq(*pb_dst, 10);
    ck_assert_int_eq((pe_dst - pb_dst), 1);
	free(pb_dst);
}
END_TEST

START_TEST(test_keyarr_neg)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int a[6] = {-3, -3, -1, -10, -2, -2};
    pb_src = a;
    pe_src = &a[6];
    int rc;

    rc = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, 5);
    ck_assert_ptr_nonnull(pb_dst);
    ck_assert_int_eq(*pb_dst, -3);
    ck_assert_int_eq((pe_dst - pb_dst), 5);
	free(pb_dst);
}
END_TEST

Suite* key_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("key");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, tests_empty_arr);
    tcase_add_test(tc_neg, tests_empty_keyarr);
    tcase_add_test(tc_neg, test_key_wrong_ptrs_not);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_key_usual);
    tcase_add_test(tc_pos, test_keyarr_one);
    tcase_add_test(tc_pos, test_keyarr_neg);
    suite_add_tcase(s, tc_pos);

    return s;
}
