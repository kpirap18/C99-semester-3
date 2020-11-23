#include "check_main.h"

START_TEST(tests_reverse0)
{
    FILE *f;
    f = fopen("unit_tests/f9.txt", "r");
    if (f)
    {
        node_t *list = NULL;
        int rc = inputstring(f, &list);
        ck_assert_int_eq(rc, OK);
        list = reverse(list);
        node_t *tmp = list;
        ck_assert_int_eq(tmp->string[0], 't');
        ck_assert_int_eq(tmp->string[1], 'y');
        tmp = tmp->next;
        ck_assert_int_eq(tmp->string[0], 'q');
        ck_assert_int_eq(tmp->string[1], 'w');
        ck_assert_int_eq(tmp->string[2], 'e');
        ck_assert_int_eq(tmp->string[3], 'r');
        fclose(f);
        listfree(list);
    }
}
END_TEST

START_TEST(tests_reverse1)
{
    FILE *f;
    f = fopen("unit_tests/f1.txt", "r");
    if (f)
    {
        node_t *list = NULL;
        int rc = inputstring(f, &list);
        ck_assert_int_eq(rc, OK);
        list = reverse(list);
        node_t *tmp = list;
        ck_assert_int_eq(tmp->string[0], 'v');
        ck_assert_int_eq(tmp->string[1], 'e');
        ck_assert_int_eq(tmp->string[2], ' ');
        ck_assert_int_eq(tmp->string[3], 'C');
        tmp = tmp->next;
        ck_assert_int_eq(tmp->string[0], 'I');
        ck_assert_int_eq(tmp->string[1], ' ');
        ck_assert_int_eq(tmp->string[2], 'l');
        ck_assert_int_eq(tmp->string[3], 'o');
        fclose(f);
        listfree(list);
    }
}
END_TEST

START_TEST(tests_reverse2)
{
    FILE *f;
    f = fopen("unit_tests/f2.txt", "r");
    if (f)
    {
        node_t *list = NULL;
        int rc = inputstring(f, &list);
        ck_assert_int_eq(rc, OK);
        list = reverse(list);
        node_t *tmp = list;
        ck_assert_int_eq(tmp->string[0], 's');
        listfree(list);
    }
}
END_TEST

START_TEST(tests_reverse_none)
{
    node_t *head = NULL;
    node_t *new = reverse(head);
    ck_assert_ptr_eq(new, NULL);
	listfree(head);
}
END_TEST

Suite* reverse_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("reverse");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_reverse0);
    tcase_add_test(tc_pos, tests_reverse1);
    tcase_add_test(tc_pos, tests_reverse2);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, tests_reverse_none);
    suite_add_tcase(s, tc_neg);

    return s;
}
