#include "check_main.h"

START_TEST(tests_len1)
{
    int a = 132;
    
    int len = leninsystem(a, 16);
    ck_assert_int_eq(len, 2);    
}
END_TEST

START_TEST(tests_len2)
{
    int a = 10;
    
    int len = leninsystem(a, 16);
    ck_assert_int_eq(len, 1); 
}
END_TEST

START_TEST(tests_len3)
{
    int a = 16;
    
    int len = leninsystem(a, 16);
    ck_assert_int_eq(len, 2);   
}
END_TEST

START_TEST(tests_len4)
{
    int a = 0;
    
    int len = leninsystem(a, 16);
    ck_assert_int_eq(len, 0);
}
END_TEST

START_TEST(tests_len5)
{
    int a = 8;
    
    int len = leninsystem(a, 8);
    ck_assert_int_eq(len, 2);
}
END_TEST

START_TEST(tests_len6)
{
    int a = 7;
    
    int len = leninsystem(a, 8);
    ck_assert_int_eq(len, 1);
}
END_TEST

START_TEST(tests_len7)
{
    int a = 15;
    
    int len = leninsystem(a, 8);
    ck_assert_int_eq(len, 2);
}
END_TEST

START_TEST(tests_len8)
{
    int a = 7;
    
    int len = leninsystem(a, 2);
    ck_assert_int_eq(len, 3);
}
END_TEST

START_TEST(tests_len9)
{
    int a = 1;
    
    int len = leninsystem(a, 2);
    ck_assert_int_eq(len, 1);
}
END_TEST

START_TEST(tests_len10)
{
    int a = 2;
    
    int len = leninsystem(a, 2);
    ck_assert_int_eq(len, 2);
}
END_TEST

Suite* leninsystem_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("leninsystem");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_len1);
    tcase_add_test(tc_pos, tests_len2);
    tcase_add_test(tc_pos, tests_len3);
    tcase_add_test(tc_pos, tests_len4);
    tcase_add_test(tc_pos, tests_len5);
    tcase_add_test(tc_pos, tests_len6);
    tcase_add_test(tc_pos, tests_len7);
    tcase_add_test(tc_pos, tests_len8);
    tcase_add_test(tc_pos, tests_len9);
    tcase_add_test(tc_pos, tests_len10);
    suite_add_tcase(s, tc_pos);
    
    return s;
}