#include "check_main.h"

START_TEST(tests_listcreatenode1)
{
    int w = 2;
    node_t *node = listcreatenode((void *)&w);
    ck_assert_int_eq(*((int *)node->data), 2);
    ck_assert_ptr_ne(node, NULL);
    listfree(node);
}
END_TEST

START_TEST(tests_listcreatenode2)
{
    int w = 355;
    node_t *node = listcreatenode((void *)&w);
    ck_assert_int_eq(*((int *)node->data), 355);
    ck_assert_ptr_ne(node, NULL);
    listfree(node);
}
END_TEST

START_TEST(tests_listcreatenode3)
{
    int w = 9;
    node_t *node = listcreatenode((void *)&w);
    ck_assert_int_eq(*((int *)node->data), 9);
    ck_assert_ptr_ne(node, NULL);
    listfree(node);
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
