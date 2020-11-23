#include "check_main.h"

START_TEST(tests_listadd)
{
    FILE *f;
    f = fopen("func_tests/f1.txt", "r");
    if (f)
    {
        node_t *head = NULL;
        char str[10] = "d";
        int pos = 0;
        int len = 1;
        node_t *node = listcreatenode(str, &pos, &len);
        inputstring(f, &head);
        ck_assert_ptr_ne(head, NULL);
        head = listaddbegin(head, node);
		node_t *tmp = head;
        ck_assert_int_eq(tmp->string[0], 'I');
        ck_assert_int_eq(tmp->string[1], ' ');
        ck_assert_int_eq(tmp->string[2], 'l');
        ck_assert_int_eq(tmp->string[3], 'o');
        tmp = tmp->next;
        ck_assert_int_eq(tmp->string[0], 'v');
        ck_assert_int_eq(tmp->string[1], 'e');
        ck_assert_int_eq(tmp->string[2], ' ');
        ck_assert_int_eq(tmp->string[3], 'C');
        tmp = tmp->next;
        ck_assert_int_eq(tmp->string[0], 'd');
        fclose(f);
        listfree(head);
    }
}
END_TEST

START_TEST(tests_listadd_one)
{
    FILE *f;
    f = fopen("func_tests/f1.txt", "r");
    if (f)
    {
        node_t *head = NULL;
        char str[10] = "qwe";
        int pos = 0;
        int len = 3;
        node_t *node = listcreatenode(str, &pos, &len);
        inputstring(f, &head);
        ck_assert_ptr_ne(head, NULL);
        head = listaddbegin(head, node);
		node_t *tmp = head;
        ck_assert_int_eq(tmp->string[0], 'I');
        ck_assert_int_eq(tmp->string[1], ' ');
        ck_assert_int_eq(tmp->string[2], 'l');
        ck_assert_int_eq(tmp->string[3], 'o');
        tmp = tmp->next;
        ck_assert_int_eq(tmp->string[0], 'v');
        ck_assert_int_eq(tmp->string[1], 'e');
        ck_assert_int_eq(tmp->string[2], ' ');
        ck_assert_int_eq(tmp->string[3], 'C');
        tmp = tmp->next;
        ck_assert_int_eq(tmp->string[0], 'q');
        ck_assert_int_eq(tmp->string[1], 'w');
        ck_assert_int_eq(tmp->string[2], 'e');
        fclose(f);
        listfree(head);
    }
}
END_TEST

START_TEST(tests_listadd_none)
{
    node_t *head = NULL;
    char str[10] = "qwe";
    int pos = 0;
    int len = 3;
    node_t *node = listcreatenode(str, &pos, &len);
    head = listaddbegin(head, node);
	node_t *tmp = head;
    ck_assert_int_eq(tmp->string[0], 'q');
    ck_assert_int_eq(tmp->string[1], 'w');
    ck_assert_int_eq(tmp->string[2], 'e');
    listfree(head);
}
END_TEST

Suite* listaddbegin_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("listaddbegin");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_listadd);
    tcase_add_test(tc_pos, tests_listadd_one);
    tcase_add_test(tc_pos, tests_listadd_none);
    suite_add_tcase(s, tc_pos);

    return s;
}
