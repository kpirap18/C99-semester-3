#include "check_main.h"

START_TEST(tests_find)
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
        fclose(f);
        listfree(head);
        listonefree(data);
    }
}
END_TEST

START_TEST(tests_find_one)
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
        fclose(f);
        listfree(head);
        listonefree(data);
    }
}
END_TEST

START_TEST(tests_find_none)
{
    node_t *head = NULL;
    int num = 3;
    node_t *new = find(head, &num, comparator_int);
    ck_assert_ptr_eq(new, NULL);
    listfree(head);
}
END_TEST

Suite* find_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("find");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_find);
    tcase_add_test(tc_pos, tests_find_one);
    tcase_add_test(tc_pos, tests_find_none);
    suite_add_tcase(s, tc_pos);

    return s;
}
