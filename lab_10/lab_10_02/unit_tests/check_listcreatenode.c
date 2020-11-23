#include "check_main.h"

START_TEST(tests_listcreatenode1)
{
    char str[5] = "qwe";
    int pos = 0;
    int len = 3;
    node_t *node = listcreatenode(str, &pos, &len);
    ck_assert_int_eq(node->string[0], 'q');
    ck_assert_int_eq(node->string[1], 'w');
    ck_assert_int_eq(node->string[2], 'e');
    ck_assert_ptr_ne(node, NULL);
    listfree(node);
}
END_TEST

START_TEST(tests_listcreatenode2)
{
    char str[10] = "qwerty";
    int pos = 3;
    int len = 4;
    node_t *node = listcreatenode(str, &pos, &len);
    ck_assert_int_eq(node->string[0], 'r');
    ck_assert_int_eq(node->string[1], 't');
    ck_assert_int_eq(node->string[2], 'y');
    ck_assert_ptr_ne(node, NULL);
    listfree(node);
}
END_TEST

START_TEST(tests_listcreatenode3)
{
    char str[10] = "d";
    int pos = 0;
    int len = 1;
    node_t *node = listcreatenode(str, &pos, &len);
    ck_assert_int_eq(node->string[0], 'd');
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
