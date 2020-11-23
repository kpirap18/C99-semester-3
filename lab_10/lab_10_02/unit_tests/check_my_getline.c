#include "check_main.h"

START_TEST(tests_my_getline_usual)
{
    FILE *f;
    char *str = NULL;
    size_t len = 0;
    f = fopen("unit_tests/f1.txt", "r");
    if (f)
    {
        ssize_t read = my_getline(&str, &len, f);
        ck_assert_int_eq((int)len, 8);
        ck_assert_int_eq((int)read, 8);
        ck_assert_ptr_ne(str, NULL);
        ck_assert_str_eq(str, "I love C");
        fclose(f);
        free(str);
    }
}
END_TEST

START_TEST(tests_my_getline_one)
{
    FILE *f;
    char *str = NULL;
    size_t len = 0;
    f = fopen("unit_tests/f2.txt", "r");
    if (f)
    {
        ssize_t read = my_getline(&str, &len, f);
        ck_assert_int_eq((int)len, 1);
        ck_assert_int_eq((int)read, 1);
        ck_assert_ptr_ne(str, NULL);
        ck_assert_str_eq(str, "s");
        fclose(f);
        free(str);
    }
}
END_TEST

START_TEST(tests_my_getline_none)
{
    FILE *f;
    char *str = NULL;
    size_t len = 0;
    f = fopen("unit_tests/f3.txt", "r");
    if (f)
    {
        ssize_t read = my_getline(&str, &len, f);
        ck_assert_int_eq((int)len, 0);
        ck_assert_int_eq((int)read, -1);
        ck_assert_ptr_eq(str, NULL);
        fclose(f);
        free(str);
    }
}
END_TEST


Suite* my_getline_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("my_getline");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_my_getline_usual);
    tcase_add_test(tc_pos, tests_my_getline_one);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, tests_my_getline_none);
    suite_add_tcase(s, tc_neg);

    return s;
}
