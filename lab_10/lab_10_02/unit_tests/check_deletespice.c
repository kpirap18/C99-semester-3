#include "check_main.h"

START_TEST(tests_delete1)
{
    FILE *f;
    f = fopen("unit_tests/f13.txt", "r");
    if (f)
    {
        node_t *list = NULL;
        int rc = inputstring(f, &list);
        ck_assert_int_eq(rc, OK);
        deletespice(list);
        node_t *tmp = list;
        compact(list);
        ck_assert_int_eq(tmp->string[0], 'q');
        ck_assert_int_eq(tmp->string[1], 'w');
        ck_assert_int_eq(tmp->string[2], 'e');
        ck_assert_int_eq(tmp->string[3], ' ');
        tmp = tmp->next;
        ck_assert_int_eq(tmp->string[0], 'r');
        ck_assert_int_eq(tmp->string[1], 't');
        ck_assert_int_eq(tmp->string[2], 'y');
        ck_assert_int_eq(tmp->string[3], ' ');
        fclose(f);
        listfree(list);
    }
}
END_TEST

START_TEST(tests_delete2)
{
    FILE *f;
    f = fopen("unit_tests/f1.txt", "r");
    if (f)
    {
        node_t *list = NULL;
        int rc = inputstring(f, &list);
        ck_assert_int_eq(rc, OK);
        deletespice(list);
        node_t *tmp = list;
        ck_assert_int_eq(tmp->string[0], 'I');
        ck_assert_int_eq(tmp->string[1], ' ');
        ck_assert_int_eq(tmp->string[2], 'l');
        ck_assert_int_eq(tmp->string[3], 'o');
        fclose(f);
        listfree(list);
    }
}
END_TEST

START_TEST(tests_delete3)
{
    FILE *f;
    f = fopen("unit_tests/f2.txt", "r");
    if (f)
    {
        node_t *list = NULL;
        int rc = inputstring(f, &list);
        ck_assert_int_eq(rc, OK);
        deletespice(list);
        node_t *tmp = list;
        ck_assert_int_eq(tmp->string[0], 's');
        fclose(f);
        listfree(list);
    }
}
END_TEST

Suite* deletespice_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("deletespice");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_delete1);
    tcase_add_test(tc_pos, tests_delete2);
    tcase_add_test(tc_pos, tests_delete3);
    suite_add_tcase(s, tc_pos);

    return s;
}
