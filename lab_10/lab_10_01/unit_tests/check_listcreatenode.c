#include "check_main.h"

START_TEST(tests_listcreatenode1)
{
    node_t *data = listcreatenode("I’m Bored", "Michael Ian Black");
    book_r d = { "I’m Bored", "Michael Ian Black" };
    int rc = comparator_book(&d, data->data);
    ck_assert_int_eq(rc, 0);
    listonefree(data);
}
END_TEST

START_TEST(tests_listcreatenode2)
{
    node_t *data = listcreatenode("I", "Mi");
    book_r d = { "I", "Mi" };
    int rc = comparator_book(&d, data->data);
    ck_assert_int_eq(rc, 0);
    listonefree(data);
}
END_TEST

START_TEST(tests_listcreatenode3)
{
    node_t *data = listcreatenode("I.", "Mi. ");
    book_r d = { "I.", "Mi. " };
    int rc = comparator_book(&d, data->data);
    ck_assert_int_eq(rc, 0);
    listonefree(data);
}
END_TEST

Suite* listcreatenode_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("listcreatenode");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_listcreatenode1);
    tcase_add_test(tc_pos, tests_listcreatenode2);
    tcase_add_test(tc_pos, tests_listcreatenode3);
    suite_add_tcase(s, tc_pos);

    return s;
}
