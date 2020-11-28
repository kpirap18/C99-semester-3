#include "check_main.h"

START_TEST(tests_len1)
{
    int a = 12345;
    
    int len = lennumber(a);
    ck_assert_int_eq(len, 5);    
}
END_TEST

START_TEST(tests_len2)
{
    int a = 111;
    
    int len = lennumber(a);
    ck_assert_int_eq(len, 3); 
}
END_TEST

START_TEST(tests_len3)
{
    int a = -87;
    
    int len = lennumber(a);
    ck_assert_int_eq(len, 2);    
}
END_TEST

START_TEST(tests_len4)
{
    int a = 0;
    
    int len = lennumber(a);
    ck_assert_int_eq(len, 0);
}
END_TEST

Suite* lennumber_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("lennumber");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_len1);
    tcase_add_test(tc_pos, tests_len2);
    tcase_add_test(tc_pos, tests_len3);
    tcase_add_test(tc_pos, tests_len4);
    suite_add_tcase(s, tc_pos);
    
    return s;
}
