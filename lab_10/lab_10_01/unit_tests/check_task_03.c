#include "check_main.h"

START_TEST(tests_sort_usual)
{
    FILE *f;
    f = fopen("func_tests/pos_in_01.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f);
        head = sort(head, comparator_book);
        book_r data = { "A Christmas Carol", "Charles Dickens" };
        int rc = comparator_book(head->data, &data);
        ck_assert_int_eq(rc, 0);
        fclose(f);
        listfree(head);
    }
}
END_TEST

START_TEST(tests_sort_one)
{
    FILE *f;
    f = fopen("func_tests/pos_in_02.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f);
        head = sort(head, comparator_book);
        book_r data = { "I’m Bored", "Michael Ian Black" };
        int rc = comparator_book(head->data, &data);
        ck_assert_int_eq(rc, 0);
        fclose(f);
        listfree(head);
    }
}
END_TEST

START_TEST(tests_sort_sort)
{
    FILE *f;
    f = fopen("func_tests/f3.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f);
        head = sort(head, comparator_book);
        book_r data = { "A Christmas Carol", "Charles Dickens" };
        int rc = comparator_book(head->data, &data);
        ck_assert_int_eq(rc, 0);
        fclose(f);
        listfree(head);
    }
}
END_TEST

START_TEST(tests_sort_unsort)
{
    FILE *f;
    f = fopen("func_tests/f1.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f);
        head = sort(head, comparator_book);
        book_r data = { "The Million Pound Bank", "Mark Twain" };
        int rc = comparator_book(head->data, &data);
        ck_assert_int_eq(rc, 0);
        fclose(f);
        listfree(head);
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