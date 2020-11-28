#include "check_main.h"

START_TEST(tests_popb_usual)
{
    FILE *f;
    f = fopen("func_tests/pos_in_01.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f);
        void *new = pop_back(&head);
        book_r data = { "Mary Poppins", "P. L. Travers" };
        int rc = comparator_book(new, &data);
        ck_assert_int_eq(rc, 0);
        fclose(f);
        listfree(head);
        freebook(new);
    }
}
END_TEST

START_TEST(tests_popb_one)
{
    FILE *f;
    f = fopen("func_tests/pos_in_02.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f);
        void *new = pop_back(&head);
        book_r data = { "I’m Bored", "Michael Ian Black" };
        int rc = comparator_book(new, &data);
        ck_assert_int_eq(rc, 0);
        fclose(f);
        listfree(head);
        freebook(new);
    }
}
END_TEST

START_TEST(tests_popf_usual)
{
    FILE *f;
    f = fopen("func_tests/pos_in_01.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f);
        void *new = pop_front(&head);
        book_r data = { "I’m Bored", "Michael Ian Black" };
        int rc = comparator_book(new, &data);
        ck_assert_int_eq(rc, 0);
        fclose(f);
        listfree(head);
        freebook(new);
    }
}
END_TEST

START_TEST(tests_popf_one)
{
    FILE *f;
    f = fopen("func_tests/pos_in_02.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f);
        void *new = pop_front(&head);
        book_r data = { "I’m Bored", "Michael Ian Black" };
        int rc = comparator_book(new, &data);
        ck_assert_int_eq(rc, 0);
        fclose(f);
        listfree(head);
        freebook(new);
    }
}
END_TEST

START_TEST(tests_popf_none)
{
    node_t *head = NULL;
    node_t *new = pop_front(&head);
    ck_assert_ptr_eq(new, NULL);
}
END_TEST

Suite* pop_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("pop");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_popb_usual);
    tcase_add_test(tc_pos, tests_popb_one);
	tcase_add_test(tc_pos, tests_popf_usual);
    tcase_add_test(tc_pos, tests_popf_one);
    tcase_add_test(tc_pos, tests_popf_none);
    suite_add_tcase(s, tc_pos);

    return s;
}
