#include "check_main.h"

START_TEST(tests_listread)
{
    FILE *f;
    f = fopen("func_tests/pos_in_01.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f);
        node_t *cur = head->next;
        book_r data = { "I’m Bored", "Michael Ian Black" };
        int rc = comparator_book(head->data, &data);
        ck_assert_int_eq(rc, 0);
        book_r data1 = { "Michael Ian Black", "Click, Clack, Moo: Cows That Type" };
        rc = comparator_book(cur->data, &data1);
        fclose(f);
        listfree(head);
    }
}
END_TEST

START_TEST(tests_listread_one)
{
    FILE *f;
    f = fopen("func_tests/pos_in_02.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f);
        book_r data = { "I’m Bored", "Michael Ian Black" };
        int rc = comparator_book(head->data, &data);
        ck_assert_int_eq(rc, 0);
        fclose(f);
        listfree(head);
    }
}
END_TEST

START_TEST(tests_listread_none)
{
    FILE *f;
    f = fopen("func_tests/neg_in_01.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f);
        ck_assert_ptr_eq(head, NULL);
        fclose(f);
        listfree(head);
    }
}
END_TEST

START_TEST(tests_listread_uncorrect)
{
    FILE *f;
    int *num = NULL;
    f = fopen("func_tests/neg_in_03.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f);
        ck_assert_ptr_eq(head, NULL);
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
