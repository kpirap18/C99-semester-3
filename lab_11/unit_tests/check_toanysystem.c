#include "check_main.h"

static int my_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
        {
			return -1;
        }
        i++;
	}
	if (s1[i] != '\0' || s2[i] != '\0')
    {
		return -1;
    }

    return 0;
}


START_TEST(tests_intstr1)
{
    int a = 12345;
    char s[50] = "\0";
    
    int len = toanysystem(s, a, 16);
    int rc = my_strcmp(s, "3039");
    ck_assert_int_eq(rc, 0);
    ck_assert_int_eq(len, 4);    
}
END_TEST

START_TEST(tests_intstr2)
{
    int a = 1;
    char s[50] = "\0";
    
    int len = toanysystem(s, a, 16);
    int rc = my_strcmp(s, "1");
    ck_assert_int_eq(rc, 0);
    ck_assert_int_eq(len, 1); 
}
END_TEST

START_TEST(tests_intstr3)
{
    int a = 0;
    char s[50] = "\0";
    
    int len = toanysystem(s, a, 16);
    int rc = my_strcmp(s, "");
    ck_assert_int_eq(rc, 0);
    ck_assert_int_eq(len, 0);    
}
END_TEST

START_TEST(tests_intstr4)
{
    int a = 98;
    char s[50] = "\0";
    
    int len = toanysystem(s, a, 16);
    int rc = my_strcmp(s, "62");
    ck_assert_int_eq(rc, 0);
    ck_assert_int_eq(len, 2); 
}
END_TEST

Suite* toanysystem_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("toanysystem");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_intstr1);
    tcase_add_test(tc_pos, tests_intstr2);
    tcase_add_test(tc_pos, tests_intstr3);
    tcase_add_test(tc_pos, tests_intstr4);
    suite_add_tcase(s, tc_pos);
    
    return s;
}