#include "check_main.h"

START_TEST(tests_sort_usual)
{
    FILE *f;
    f = fopen("../func_tests/f1.txt", "r");
    if (f)
    {
        int *num = NULL;
        node_t *head;
        head = listread(f, &num);
        node_t *new = sort(head, comparator_int);
        node_t *cur = new;
        ck_assert_int_eq(*((int *)cur->data), 2);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 4);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 5);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 6);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 7);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 8);
        fclose(f);
        listfree(head);
        free(num);
    }
}
END_TEST

START_TEST(tests_sort_one)
{
    FILE *f;
    f = fopen("../func_tests/f2.txt", "r");
    if (f)
    {
        int *num = NULL;
        node_t *head;
        head = listread(f, &num);
        node_t *new = sort(head, comparator_int);
        node_t *cur = new;
        ck_assert_int_eq(*((int *)cur->data), 1);
        fclose(f);
        listfree(head);
        free(num);
    }
}
END_TEST

START_TEST(tests_sort_sort)
{
    FILE *f;
    f = fopen("../func_tests/f3.txt", "r");
    if (f)
    {
        int *num = NULL;
        node_t *head;
        head = listread(f, &num);
        node_t *new = sort(head, comparator_int);
        node_t *cur = new;
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

START_TEST(tests_sort_unsort)
{
    FILE *f;
    f = fopen("../func_tests/f4.txt", "r");
    if (f)
    {
        int *num = NULL;
        node_t *head;
        head = listread(f, &num);
        node_t *new = sort(head, comparator_int);
        node_t *cur = new;
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


Suite* sort_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("sort");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_sort_usual);
    tcase_add_test(tc_pos, tests_sort_one);
    tcase_add_test(tc_pos, tests_sort_sort);
    tcase_add_test(tc_pos, tests_sort_unsort);
    suite_add_tcase(s, tc_pos);

    return s;
}