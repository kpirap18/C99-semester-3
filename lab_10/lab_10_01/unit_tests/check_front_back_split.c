#include "check_main.h"

START_TEST(tests_front_back_7)
{
    FILE *f;
    f = fopen("func_tests/pos_in_01.txt", "r");
    if (f)
    {
        node_t *head, *back = NULL;
        head = listread(f);
        front_back_split(head, &back);
        book_r data = { "I’m Bored", "Michael Ian Black" };
        int rc = comparator_book(head->data, &data);
        ck_assert_int_eq(rc, 0);
        book_r data1 = { "Treasure Island", "Robert Louis Stevenson" };
        rc = comparator_book(back->data, &data1);
        ck_assert_int_eq(rc, 0);
        fclose(f);
        listfree(head);
		listfree(back);
    }
}
END_TEST

START_TEST(tests_front_back_1)
{
    FILE *f;
    f = fopen("func_tests/pos_in_02.txt", "r");
    if (f)
    {
        node_t *head, *back = NULL;
        head = listread(f);
        front_back_split(head, &back);
        book_r data = { "I’m Bored", "Michael Ian Black" };
        int rc = comparator_book(head->data, &data);
        ck_assert_int_eq(rc, 0);
		ck_assert_ptr_eq(back, NULL);		
        fclose(f);
        listfree(head);
    }
}
END_TEST

START_TEST(tests_front_back_none)
{
    node_t *head = NULL, *back = NULL;
    front_back_split(head, &back);
    ck_assert_ptr_eq(head, NULL);
	ck_assert_ptr_eq(back, NULL);
}
END_TEST

Suite* front_back_split_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("front_back_split");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_front_back_7);
    tcase_add_test(tc_pos, tests_front_back_1);
    tcase_add_test(tc_pos, tests_front_back_none);
    suite_add_tcase(s, tc_pos);

    return s;
}
