#include "check_main.h"

START_TEST(tests_count1)
{
    FILE *f;
    f = fopen("unit_tests/f9.txt", "r");
    if (f)
    {
        node_t *list = NULL;
        int rc = inputstring(f, &list);
        ck_assert_int_eq(rc, OK);
        int len = 0;
        listcount(list, &len);
        ck_assert_int_eq(len, 2);
        fclose(f);
        listfree(list);
    }
}
END_TEST

START_TEST(tests_count2)
{
    FILE *f;
    f = fopen("unit_tests/f1.txt", "r");
    if (f)
    {
        node_t *list = NULL;
        int rc = inputstring(f, &list);
        ck_assert_int_eq(rc, OK);
        int len = 0;
        listcount(list, &len);
        ck_assert_int_eq(len, 2);
        fclose(f);
        listfree(list);
    }
}
END_TEST

START_TEST(tests_count3)
{
    FILE *f;
    f = fopen("unit_tests/f2.txt", "r");
    if (f)
    {
        node_t *list = NULL;
        int rc = inputstring(f, &list);
        ck_assert_int_eq(rc, OK);
        int len = 0;
        listcount(list, &len);
        ck_assert_int_eq(len, 1);
        fclose(f);
        listfree(list);
    }
}
END_TEST

START_TEST(tests_count4)
{
    FILE *f;
    f = fopen("unit_tests/f13.txt", "r");
    if (f)
    {
        node_t *list = NULL;
        int rc = inputstring(f, &list);
        ck_assert_int_eq(rc, OK);
        int len = 0;
        listcount(list, &len);
        ck_assert_int_eq(len, 6);
        fclose(f);
        listfree(list);
    }
}
END_TEST

START_TEST(tests_count0)
{
    int len = 0;
    listcount(NULL, &len);
    ck_assert_int_eq(len, 0);
}
END_TEST

Suite* listcount_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("listcount");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_count0);
    tcase_add_test(tc_pos, tests_count1);
    tcase_add_test(tc_pos, tests_count2);
    tcase_add_test(tc_pos, tests_count3);
    tcase_add_test(tc_pos, tests_count4);
    suite_add_tcase(s, tc_pos);

    return s;
}
