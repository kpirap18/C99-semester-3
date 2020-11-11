#include "check_main.h"

START_TEST(tests_listread)
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
        ck_assert_int_eq(*((int *)cur->data), 1);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 2);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 3);
        cur = cur->next;
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 4);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 5);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 6);
        cur = cur->next;
        ck_assert_int_eq(*((int *)cur->data), 7);
        fclose(f);
        listfree(head);
        free(num);
    }
}
END_TEST

START_TEST(tests_listread_one)
{
    FILE *f;
    int *num = NULL;
    f = fopen("../func_tests/pos_02_in.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f, &num);
        node_t* cur = head;
        ck_assert_ptr_eq(head, NULL);
        ck_assert_int_eq(*((int *)cur->data), 1);
        fclose(f);
        listfree(head);
        free(num);
    }
}
END_TEST

START_TEST(tests_listread_none)
{
    FILE *f;
    int *num = NULL;
    f = fopen("../func_tests/neg_01_in.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f, &num);
        ck_assert_ptr_eq(head, NULL);
        fclose(f);
        listfree(head);
        free(num);
    }
}
END_TEST

START_TEST(tests_listread_uncorrect)
{
    FILE *f;
    int *num = NULL;
    f = fopen("../func_tests/neg_04_in.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f, &num);
        ck_assert_ptr_ne(head, NULL);
        fclose(f);
        listfree(head);
        free(num);
    }
}
END_TEST

Suite* listread_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("listread");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_listread);
    tcase_add_test(tc_pos, tests_listread_one);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, tests_listread_none);
    tcase_add_test(tc_neg, tests_listread_uncorrect);
    suite_add_tcase(s, tc_neg);

    return s;
}
