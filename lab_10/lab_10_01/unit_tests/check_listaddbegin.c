#include "check_main.h"

START_TEST(tests_listadd)
{
    FILE *f;
    f = fopen("func_tests/pos_in_01.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f);
        node_t *data1 = listcreatenode("I", "M");
        head = listaddbegin(head, data1);
        int rc = comparator_book(head->data, data1->data);
        ck_assert_int_eq(rc, 0);
        fclose(f);
        listfree(head);
    }
}
END_TEST

START_TEST(tests_listadd_one)
{
    FILE *f;
    f = fopen("func_tests/pos_in_02.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f);
        node_t *data1 = listcreatenode("I", "M");
        head = listaddbegin(head, data1);
        int rc = comparator_book(head->data, data1->data);
        ck_assert_int_eq(rc, 0);
        fclose(f);
        listfree(head);
    }
}
END_TEST

START_TEST(tests_listadd_none)
{
    node_t *head = NULL;
    node_t *data1 = listcreatenode("I", "M");
    head = listaddbegin(head, data1);
    int rc = comparator_book(head->data, data1->data);
    ck_assert_int_eq(rc, 0);
    listfree(head);
}
END_TEST

Suite* listaddbegin_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("listaddbegin");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_listadd);
    tcase_add_test(tc_pos, tests_listadd_one);
    tcase_add_test(tc_pos, tests_listadd_none);
    suite_add_tcase(s, tc_pos);

    return s;
}
