#include "check_main.h"

START_TEST(tests_copy_one)
{
    FILE *f;
    f = fopen("func_tests/pos_in_02.txt", "r");
    if (f)
    {
        node_t *head_a, *head_b;
        head_a = listread(f);
        int rc = copy(head_a, &head_b);
		ck_assert_int_eq(rc, OK);
        book_r data = { "I’m Bored", "Michael Ian Black" };
        rc = comparator_book(head_b->data, &data);
        ck_assert_int_eq(rc, 0);
        fclose(f);
        listfree(head_a);
        free(head_b);
    }
}
END_TEST

START_TEST(tests_copy_none)
{
    node_t *head_a = NULL, *head_b;
    int rc = copy(head_a, &head_b);
    ck_assert_ptr_eq(head_b, NULL);
	ck_assert_int_eq(rc, INVALID_ARG);
}
END_TEST

Suite* copy_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("copy");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_copy_one);
	tcase_add_test(tc_pos, tests_copy_none);
    suite_add_tcase(s, tc_pos);

    return s;
}
























