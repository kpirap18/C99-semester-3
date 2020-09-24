#include "../inc/check_main.h"

START_TEST(tests_arr_one_parsing)
{
    int *pa, *pa1;
    int a[1] = {1};
    pa = a;
    pa1 = a + 1;
    int b[1];
    int *pb = b;

    parsing_key_array(pb, pa, pa1, 0);
    ck_assert_int_eq(*pb, 1);
}
END_TEST

START_TEST(tests_arr_pos_parsing)
{
    int *pa, *pa1;
    int a[5] = {1, 4, 8, 9, 6};
    pa = a;
    pa1 = &a[5];
    int b[3];
    int *pb = b;

    parsing_key_array(pb, pa, pa1, 28 / 6);
    ck_assert_int_eq(*pb, 8);
    ck_assert_int_eq(*(pb + 1), 9);
    ck_assert_int_eq(*(pb + 2), 6);
}
END_TEST

START_TEST(tests_arr_neg_parsing)
{
    int *pa, *pa1;
    int a[5] = {-1, -4, -8, -9, -6};
    pa = a;
    pa1 = &a[5];
    int b[3];
    int *pb = b;

    parsing_key_array(pb, pa, pa1, -28 / 5);
    ck_assert_int_eq(*pb, -1);
    ck_assert_int_eq(*(pb + 1), -4);
}
END_TEST

START_TEST(tests_usual_parsing)
{
    int *pa, *pa1;
    int a[5] = {7, -5, 9, -8, 1};
    pa = a;
    pa1 = &a[5];
    int b[3];
    int *pb = b;

    parsing_key_array(pb, pa, pa1, -28 / 5);
    ck_assert_int_eq(*pb, 7);
    ck_assert_int_eq(*(pb + 1), 9);
    ck_assert_int_eq(*(pb + 2), 1);
}
END_TEST



Suite* parsing_key_array_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("parsing_key_array");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_arr_one_parsing);
    tcase_add_test(tc_pos, tests_arr_pos_parsing);
    tcase_add_test(tc_pos, tests_arr_neg_parsing);
    tcase_add_test(tc_pos, tests_usual_parsing);
    suite_add_tcase(s, tc_pos);

    return s;
}

