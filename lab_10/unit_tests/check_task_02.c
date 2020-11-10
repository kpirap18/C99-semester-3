#include "check_main.h"

START_TEST(tests_reverse1)
{
    FILE *f;
    int *num= NULL;
    f = fopen("../func_tests/pos_01_in.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f, &num);
        node_t *new = reverse(head);
        node_t *cur = new;
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
        ck_assert_int_eq(*((int *)cur->data), 1);
        cur = cur->next;
        fclose(f);
        listfree(head);
        free(num);
    }
}
END_TEST

START_TEST(tests_reverse_one)
{
    FILE *f;
    int *num = NULL;
    f = fopen("../func_tests/pos_02_in.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f, &num);
        node_t *new = reverse(head);
        node_t *cur = new;
        ck_assert_int_eq(*((int *)cur->data), 1);
        fclose(f);
        listfree(head);
        free(num);
    }
}
END_TEST

Suite* reverse_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("reverse");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_reverse1);
    tcase_add_test(tc_pos, tests_reverse_one);
    suite_add_tcase(s, tc_pos);

    return s;
}
