#include "check_main.h"

START_TEST(tests_insert)
{
    FILE *f;
    f = fopen("func_tests/pos_in_01.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f);
        node_t *data = listcreatenode("I’m Bored", "Michael Ian Black");
        node_t *res = find(head, data->data, comparator_book);
        int rc = comparator_book(res->data, data->data);
        ck_assert_int_eq(rc, 0);
        node_t *data1 = listcreatenode("I", "M");
        insert(&head, data1, res);
        rc = comparator_book(head->data, data1->data);
        ck_assert_int_eq(rc, 0);
        fclose(f);
        listfree(head);
        listonefree(data);
    }
}
END_TEST

START_TEST(tests_insert_one)
{
    FILE *f;
    f = fopen("func_tests/pos_in_02.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f);
        node_t *data = listcreatenode("I’m Bored", "Michael Ian Black");
        node_t *res = find(head, data->data, comparator_book);
        int rc = comparator_book(res->data, data->data);
        ck_assert_int_eq(rc, 0);
        node_t *data1 = listcreatenode("I", "M");
        insert(&head, data1, res);
        rc = comparator_book(head->data, data1->data);
        ck_assert_int_eq(rc, 0);
        fclose(f);
        listfree(head);
        listonefree(data);
    }
}
END_TEST

START_TEST(tests_insert_none)
{
    node_t *head = NULL;
    book_r data = { "I", "M" };
    node_t *data1 = listcreatenode("I", "M");
    insert(&head, data1, NULL);
    int rc = comparator_book(head->data, &data);
    ck_assert_int_eq(rc, 0);
    listfree(head);
}
END_TEST

Suite* insert_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("insert");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_insert);
    tcase_add_test(tc_pos, tests_insert_one);
    tcase_add_test(tc_pos, tests_insert_none);
    suite_add_tcase(s, tc_pos);

    return s;
}
