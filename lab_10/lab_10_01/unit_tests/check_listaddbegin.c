#include "check_main.h"

START_TEST(tests_listadd)
{
    FILE *f;
    int *num= NULL;
    f = fopen("../func_tests/pos_01_in.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f, &num);
        ck_assert_ptr_eq(head, NULL);
        node_t* cur = head;
        int w = 9;
        node_t *node = listcreatenode((void *)&w);
        head = listaddbegin(head, node);
        ck_assert_int_eq(*((int *)cur->data), 9);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 1);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 2);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 3);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 4);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 5);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 6);
        fclose(f);
        listfree(head);
        free(num);
    }
}
END_TEST

START_TEST(tests_listadd_one)
{
    FILE *f;
    int *num = NULL;
    f = fopen("../func_tests/pos_02_in.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f, &num);
        int w = 9;
        node_t *node = listcreatenode((void *)&w);
        head = listaddbegin(head, node);
        node_t* cur = head;
        ck_assert_ptr_eq(head, NULL);
        ck_assert_int_eq(*((int *)cur->data), 9);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 1);
        fclose(f);
        listfree(head);
        free(num);
    }
}
END_TEST

START_TEST(tests_listadd_none)
{
    FILE *f;
    int *num = NULL;
    f = fopen("../func_tests/neg_01_in.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f, &num);
        int w = 9;
        node_t *node = listcreatenode((void *)&w);
        head = listaddbegin(head, node);
        ck_assert_ptr_ne(head, NULL);
        ck_assert_int_eq(*((int *)head->data), 9);
        fclose(f);
        listfree(head);
        free(num);
    }
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
