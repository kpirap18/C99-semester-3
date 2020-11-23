#include "check_main.h"

START_TEST(tests_stringtolist_usual1)
{
    char str[10] = "qwerty";
    node_t *list = NULL;
    stringtolist(str, &list);
    ck_assert_int_eq(list->string[0], 'q');
    ck_assert_int_eq(list->string[1], 'w');
    ck_assert_int_eq(list->string[2], 'e');
    ck_assert_int_eq(list->string[3], 'r');
    node_t *tmp = list->next->next;
    ck_assert_ptr_eq(tmp, NULL);
    listfree(list);
}
END_TEST

START_TEST(tests_stringtolist_usual2)
{
    char str[10] = "1qw";
    node_t *list = NULL;
    stringtolist(str, &list);
    ck_assert_int_eq(list->string[0], '1');
    ck_assert_int_eq(list->string[1], 'q');
    ck_assert_int_eq(list->string[2], 'w');
    node_t *tmp = list->next;
    ck_assert_ptr_eq(tmp, NULL);
    listfree(list);
}
END_TEST

START_TEST(tests_stringtolist_usual3)
{
    char str[10] = "s";
    node_t *list = NULL;
    stringtolist(str, &list);
    ck_assert_int_eq(list->string[0], 's');
    node_t *tmp = list->next;
    ck_assert_ptr_eq(tmp, NULL);
    listfree(list);
}
END_TEST


Suite* stringtolist_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("stringtolist");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_stringtolist_usual1);
    tcase_add_test(tc_pos, tests_stringtolist_usual2);
    tcase_add_test(tc_pos, tests_stringtolist_usual3);
    suite_add_tcase(s, tc_pos);

    return s;
}
