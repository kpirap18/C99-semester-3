#include "check_main.h"

START_TEST(tests_append0)
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
        append(&list, &list2);
        compact(list);
        ck_assert_ptr_eq(list2, NULL);
        node_t *tmp = list;
        ck_assert_int_eq(tmp->string[0], 'q');
        ck_assert_int_eq(tmp->string[1], 'w');
        ck_assert_int_eq(tmp->string[2], 'e');
        ck_assert_int_eq(tmp->string[3], 'r');
        tmp = tmp->next;
        ck_assert_int_eq(tmp->string[0], 't');
        ck_assert_int_eq(tmp->string[1], 'y');
        ck_assert_int_eq(tmp->string[2], 'q');
        ck_assert_int_eq(tmp->string[3], 'w');
        fclose(f);
        listfree(list);
        listfree(list2);
    }
}
END_TEST

START_TEST(tests_append1)
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
        append(&list, &list2);
        compact(list);
        ck_assert_ptr_eq(list2, NULL);
        node_t *tmp = list;
        ck_assert_int_eq(tmp->string[0], 'q');
        ck_assert_int_eq(tmp->string[1], 'w');
        ck_assert_int_eq(tmp->string[2], 'e');
        ck_assert_int_eq(tmp->string[3], 'r');
        tmp = tmp->next;
        ck_assert_int_eq(tmp->string[0], 't');
        ck_assert_int_eq(tmp->string[1], 'y');
        ck_assert_int_eq(tmp->string[2], 'r');
        ck_assert_int_eq(tmp->string[3], 't');
        fclose(f);
        listfree(list);
        listfree(list2);
    }
}
END_TEST

START_TEST(tests_append2)
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
        append(&list, &list2);
        compact(list);
        ck_assert_ptr_eq(list2, NULL);
        node_t *tmp = list;
        ck_assert_int_eq(tmp->string[0], 'q');
        ck_assert_int_eq(tmp->string[1], 'w');
        ck_assert_int_eq(tmp->string[2], 'e');
        ck_assert_int_eq(tmp->string[3], 'r');
        tmp = tmp->next;
        ck_assert_int_eq(tmp->string[0], 't');
        ck_assert_int_eq(tmp->string[1], 'y');
        ck_assert_int_eq(tmp->string[2], 'a');
        ck_assert_int_eq(tmp->string[3], 's');
        tmp = tmp->next;
        ck_assert_int_eq(tmp->string[0], 'd');
        ck_assert_int_eq(tmp->string[1], 'f');
        ck_assert_int_eq(tmp->string[2], 'g');
        ck_assert_int_eq(tmp->string[3], 'h');
        fclose(f);
        listfree(list);
        listfree(list2);
    }
}
END_TEST

START_TEST(tests_append_error)
{
    node_t *list = NULL;
    node_t *list2 = NULL;
    append(&list, &list2);
    ck_assert_ptr_eq(list, NULL);
    ck_assert_ptr_eq(list2, NULL);
}
END_TEST

Suite* append_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("append");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_append0);
    tcase_add_test(tc_pos, tests_append1);
    tcase_add_test(tc_pos, tests_append2);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, tests_append_error);
    suite_add_tcase(s, tc_neg);

    return s;
}
