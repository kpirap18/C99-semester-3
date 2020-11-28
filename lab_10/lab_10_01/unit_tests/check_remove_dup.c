#include "check_main.h"

START_TEST(tests_remove_usual)
{
    book_r b1 = { "AAA", "111" };
    book_r b2 = { "AAA", "111" };
    book_r b3 = { "CCC", "333" };
    book_r b4 = { "DDD", "444" };
    book_r b5 = { "DDD", "444" };

    node_t *n1 = malloc(sizeof(node_t));
    if (!n1)
        return;
    node_t *n2 = malloc(sizeof(node_t));
    if (!n2)
    {
        free(n1);
        return;
    }
    node_t *n3 = malloc(sizeof(node_t));
    if (!n3)
    {
        free(n1);
        free(n2);
        return;
    }
    node_t *n4 = malloc(sizeof(node_t));
    if (!n4)
    {
        free(n1);
        free(n2);
        free(n3);
        return;
    }
    node_t *n5 = malloc(sizeof(node_t));
    if (!n5)
    {
        free(n1);
        free(n2);
        free(n3);
        free(n4);
        return;
    }
    
    n1->data = &b1;
    n1->next = n2;
    n2->data = &b2;
    n2->next = n3;
    n3->data = &b3;
    n3->next = n4;
    n4->data = &b4;
    n4->next = n5;
    n5->data = &b5;
    n5->next = NULL;
    node_t *head = n1;

    remove_duplicates(&head, comparator_book);

    book_r data1 = { "CCC", "333" };
    int rc = comparator_book(head->next->data, &data1);
    ck_assert_int_eq(rc, 0);
    free(n1);
    free(n3);
    free(n4);
}
END_TEST

START_TEST(tests_remove_none)
{
    FILE *f;
    f = fopen("func_tests/f4.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f);
        head = sort(head, comparator_book);
        remove_duplicates(&head, comparator_book);
        book_r data1 = { "I’m Bored", "Michael Ian Black" };
        int rc = comparator_book(head->data, &data1);
        ck_assert_int_eq(rc, 0);
        fclose(f);
        listfree(head);
    }
}
END_TEST

START_TEST(tests_remove_all)
{
    book_r b1 = { "AAA", "111" };
    book_r b2 = { "AAA", "111" };
    book_r b3 = { "AAA", "111" };
    book_r b4 = { "AAA", "111" };
    book_r b5 = { "AAA", "111" };

    node_t *n1 = malloc(sizeof(node_t));
    if (!n1)
        return;
    node_t *n2 = malloc(sizeof(node_t));
    if (!n2)
    {
        free(n1);
        return;
    }
    node_t *n3 = malloc(sizeof(node_t));
    if (!n3)
    {
        free(n1);
        free(n2);
        return;
    }
    node_t *n4 = malloc(sizeof(node_t));
    if (!n4)
    {
        free(n1);
        free(n2);
        free(n3);
        return;
    }
    node_t *n5 = malloc(sizeof(node_t));
    if (!n5)
    {
        free(n1);
        free(n2);
        free(n3);
        free(n4);
        return;
    }
    
    n1->data = &b1;
    n1->next = n2;
    n2->data = &b2;
    n2->next = n3;
    n3->data = &b3;
    n3->next = n4;
    n4->data = &b4;
    n4->next = n5;
    n5->data = &b5;
    n5->next = NULL;
    node_t *head = n1;

    remove_duplicates(&head, comparator_book);

    book_r data1 = { "AAA", "111" };
    int rc = comparator_book(head->data, &data1);
    ck_assert_ptr_eq(head->next, NULL);
    ck_assert_int_eq(rc, 0);
    free(n1);
}
END_TEST

START_TEST(tests_remove_null)
{
    node_t *head = NULL;
    remove_duplicates(&head, comparator_int);
    ck_assert_ptr_eq(head, NULL);
}
END_TEST

Suite* remove_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("remove");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_remove_usual);
    tcase_add_test(tc_pos, tests_remove_none);
    tcase_add_test(tc_pos, tests_remove_all);
    tcase_add_test(tc_pos, tests_remove_null);
    suite_add_tcase(s, tc_pos);

    return s;
}
