#include "check_main.h"

START_TEST(tests_strlen1)
{
    char s1[BUFSIZE] = "qqq 1 12 11 a";
    
    int len = my_strlen(s1);
    ck_assert_int_eq(len, 13);    
}
END_TEST

START_TEST(tests_strlen2)
{
    char s1[BUFSIZE] = "I love C";
    
    int len = my_strlen(s1);
    ck_assert_int_eq(len, 8);    
}
END_TEST

START_TEST(tests_strlen3)
{
    char s1[BUFSIZE] = " ";
    
    int len = my_strlen(s1);
    ck_assert_int_eq(len, 1);    
}
END_TEST

START_TEST(tests_strlen4)
{
    char s1[BUFSIZE] = "";
    
    int len = my_strlen(s1);
    ck_assert_int_eq(len, 0);    
}
END_TEST

Suite* my_strlen_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("my_strlen");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_strlen1);
    tcase_add_test(tc_pos, tests_strlen2);
    tcase_add_test(tc_pos, tests_strlen3);
    tcase_add_test(tc_pos, tests_strlen4);
    suite_add_tcase(s, tc_pos);
    
    return s;
}
