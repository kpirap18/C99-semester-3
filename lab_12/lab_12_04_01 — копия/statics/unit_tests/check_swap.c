#include "check_main.h"

START_TEST(tests_swap_similar)
{
    int a = 2, b = 2;
    int *aa = &a, *bb = &b;

    swap(aa, bb, sizeof(int));
    ck_assert_int_eq(*aa, 2);
    ck_assert_int_eq(*bb, 2);
}
END_TEST

START_TEST(tests_swap_neg)
{
    int a = -3, b = -5;
    int *aa = &a, *bb = &b;

    swap(aa, bb, sizeof(int));
    ck_assert_int_eq(*aa, -5);
    ck_assert_int_eq(*bb, -3);
}
END_TEST

START_TEST(tests_swap_pos)
{
    int a = 4, b = 3;
    int *aa = &a, *bb = &b;

    swap(aa, bb, sizeof(int));
    ck_assert_int_eq(*aa, 3);
    ck_assert_int_eq(*bb, 4);
}
END_TEST

START_TEST(tests_swap_pos_neg)
{
    int a = 4, b = -3;
    int *aa = &a, *bb = &b;

    swap(aa, bb, sizeof(int));
    ck_assert_int_eq(*aa, -3);
    ck_assert_int_eq(*bb, 4);
}
END_TEST
Suite* swap_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("swap");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_swap_similar);
    tcase_add_test(tc_pos, tests_swap_neg);
    tcase_add_test(tc_pos, tests_swap_pos);
    tcase_add_test(tc_pos, tests_swap_pos_neg);
    suite_add_tcase(s, tc_pos);

    return s;
}

