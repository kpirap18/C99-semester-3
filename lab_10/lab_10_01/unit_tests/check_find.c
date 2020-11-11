#include "check_main.h"

START_TEST(tests_find)
{
    FILE *f;
    int *num= NULL;
    f = fopen("../func_tests/pos_01_in.txt", "r");
    if (f)
    {
        node_t *head;
        int p = 3;
        head = listread(f, &num);
        node_t *new = find(head, &p, comparator_int);
        ck_assert_int_eq(*((int *)new->data), 7);
        fclose(f);
        listfree(head);
        free(num);
    }
}
END_TEST

START_TEST(tests_find_one)
{
    FILE *f;
    int *num = NULL;
    f = fopen("../func_tests/pos_02_in.txt", "r");
    if (f)
    {
        node_t *head;
        int p = 1;
        head = listread(f, &num);
        node_t *new = find(head, &p, comparator_int);
        ck_assert_int_eq(*((int *)new->data), 1);
        fclose(f);
        listfree(head);
        free(num);
    }
}
END_TEST

START_TEST(tests_find_none)
{
    node_t *head = NULL;
    int num = 3;
    node_t *new = find(head, &num, comparator_int);
    ck_assert_ptr_eq(new, NULL);
    listfree(head);
}
END_TEST

Suite* find_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("find");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_find);
    tcase_add_test(tc_pos, tests_find_one);
    tcase_add_test(tc_pos, tests_find_none);
    suite_add_tcase(s, tc_pos);

    return s;
}
