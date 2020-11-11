#include "check_main.h"

START_TEST(tests_pop_usual)
{
    FILE *f;
    int *num= NULL;
    f = fopen("../func_tests/pos_01_in.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f, &num);
        void *new = pop_back(&head);
        node_t *cur = head;
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
        ck_assert_int_eq(*((int *)new), 1);
        cur = cur->next;
        fclose(f);
        listfree(head);
        free(num);
        free(new);
    }
}
END_TEST

START_TEST(tests_pop_one)
{
    FILE *f;
    int *num = NULL;
    f = fopen("../func_tests/pos_02_in.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f, &num);
        node_t *new = pop_back(&head);
        ck_assert_int_eq(*((int *)new), 1);
        fclose(f);
        listfree(head);
        free(num);
        free(new);
    }
}
END_TEST

Suite* pop_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("task_01");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_pop_usual);
    tcase_add_test(tc_pos, tests_pop_one);
    suite_add_tcase(s, tc_pos);

    return s;
}

void insert(node_t **head, node_t *elem, node_t *before);
