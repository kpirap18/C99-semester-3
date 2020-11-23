#include "check_main.h"

START_TEST(tests_find_0)
{
    FILE *f;
    f = fopen("unit_tests/f9.txt", "r");
    if (f)
    {
        node_t *list = NULL;
        node_t *list2 = NULL;
        int rc = inputstring(f, &list);
        ck_assert_int_eq(rc, OK);
        rc = inputstring(f, &list2);
        ck_assert_int_eq(rc, OK);
        int pos = findpos(list, list2);
        ck_assert_int_eq(pos, 0);
        fclose(f);
        listfree(list);
        listfree(list2);
    }
}
END_TEST

START_TEST(tests_find_3)
{
    FILE *f;
    f = fopen("unit_tests/f10.txt", "r");
    if (f)
    {
        node_t *list = NULL;
        node_t *list2 = NULL;
        int rc = inputstring(f, &list);
        ck_assert_int_eq(rc, OK);
        rc = inputstring(f, &list2);
        ck_assert_int_eq(rc, OK);
        int pos = findpos(list, list2);
        ck_assert_int_eq(pos, 3);
        fclose(f);
        listfree(list);
        listfree(list2);
    }
}
END_TEST

START_TEST(tests_find_last)
{
    FILE *f;
    f = fopen("unit_tests/f11.txt", "r");
    if (f)
    {
        node_t *list = NULL;
        node_t *list2 = NULL;
        int rc = inputstring(f, &list);
        ck_assert_int_eq(rc, OK);
        rc = inputstring(f, &list2);
        ck_assert_int_eq(rc, OK);
        int pos = findpos(list, list2);
        ck_assert_int_eq(pos, 5);
        fclose(f);
        listfree(list);
        listfree(list2);
    }
}
END_TEST

START_TEST(tests_find_notfind0)
{
    FILE *f;
    f = fopen("unit_tests/f14.txt", "r");
    if (f)
    {
        node_t *list = NULL;
        node_t *list2 = NULL;
        int rc = inputstring(f, &list);
        ck_assert_int_eq(rc, OK);
        rc = inputstring(f, &list2);
        ck_assert_int_eq(rc, OK);
        int pos = findpos(list, list2);
        ck_assert_int_eq(pos, -1);
        fclose(f);
        listfree(list);
        listfree(list2);
    }
}
END_TEST

START_TEST(tests_find_notfind1)
{
    FILE *f;
    f = fopen("unit_tests/f12.txt", "r");
    if (f)
    {
        node_t *list = NULL;
        node_t *list2 = NULL;
        int rc = inputstring(f, &list);
        ck_assert_int_eq(rc, OK);
        rc = inputstring(f, &list2);
        ck_assert_int_eq(rc, OK);
        int pos = findpos(list, list2);
        ck_assert_int_eq(pos, -1);
        fclose(f);
        listfree(list);
        listfree(list2);
    }
}
END_TEST

Suite* findpos_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("findpos");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_find_0);
    tcase_add_test(tc_pos, tests_find_3);
    tcase_add_test(tc_pos, tests_find_last);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, tests_find_notfind0);
    tcase_add_test(tc_neg, tests_find_notfind1);
    suite_add_tcase(s, tc_neg);

    return s;
}
