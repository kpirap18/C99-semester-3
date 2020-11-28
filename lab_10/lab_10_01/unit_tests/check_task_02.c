#include "check_main.h"

START_TEST(tests_reverse1)
{
    FILE *f;
    f = fopen("func_tests/pos_in_01.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f);
        head = reverse(head);
        node_t *cur = head->next;
        book_r data = { "Mary Poppins", "P. L. Travers" };
        int rc = comparator_book(head->data, &data);
        ck_assert_int_eq(rc, 0);
        book_r data1 = { "The Wonderful Wizard of Oz", "Lyman Frank Baum" };
        rc = comparator_book(cur->data, &data1);
        fclose(f);
        listfree(head);
    }
}
END_TEST

START_TEST(tests_reverse_one)
{
    FILE *f;
    f = fopen("func_tests/pos_in_02.txt", "r");
    if (f)
    {
        node_t *head;
        head = listread(f);
        head = reverse(head);
        book_r data = { "I’m Bored", "Michael Ian Black" };
        int rc = comparator_book(head->data, &data);
        ck_assert_int_eq(rc, 0);
        fclose(f);
        listfree(head);
    }
}
END_TEST

START_TEST(tests_reverse_none)
{
    node_t *head = NULL;
    node_t *new = reverse(head);
    ck_assert_ptr_eq(new, NULL);
	listfree(head);
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
	tcase_add_test(tc_pos, tests_reverse_none);
    suite_add_tcase(s, tc_pos);

    return s;
}
