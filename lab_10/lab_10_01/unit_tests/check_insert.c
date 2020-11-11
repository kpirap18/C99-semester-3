#include "check_main.h"

START_TEST(tests_insert)
{
    FILE *f;
    int *num= NULL;
    f = fopen("../func_tests/pos_01_in.txt", "r");
    if (f)
    {
        node_t *head;
        int p = 1;
        int w = 2;
        head = listread(f, &num);
        node_t *before = find(head, &p, comparator_int);
        node_t *node = listcreatenode((void *)&w);
        insert(&head, node, before);
        node_t* cur = head;
        ck_assert_int_eq(*((int *)cur->data), 7);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 6);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 5);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 4);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 3);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 2);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 2);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 1);
        fclose(f);
        listfree(head);
        free(num);
    }
}
END_TEST

START_TEST(tests_insert_one)
{
    FILE *f;
    int *num = NULL;
    f = fopen("../func_tests/pos_02_in.txt", "r");
    if (f)
    {
        node_t *head;
        int p = 1;
        int w = 2;
        head = listread(f, &num);
        node_t *before = find(head, &p, comparator_int);
        node_t *node = listcreatenode((void *)&w);
        insert(&head, node, before);
        node_t* cur = head;
        ck_assert_int_eq(*((int *)cur->data), 2);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 1);
        fclose(f);
        listfree(head);
        free(num);
    }
}
END_TEST

START_TEST(tests_insert_none)
{
    FILE *f;
    int *num = NULL;
    f = fopen("../func_tests/pos_02_in.txt", "r");
    if (f)
    {
        node_t *head;
        int p = 5;
        int w = 2;
        head = listread(f, &num);
        node_t *before = find(head, &p, comparator_int);
        node_t *node = listcreatenode((void *)&w);
        insert(&head, node, before);
        node_t* cur = head;
        ck_assert_int_eq(*((int *)cur->data), 1);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 2);
        fclose(f);
        listfree(head);
        free(num);
    }
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
