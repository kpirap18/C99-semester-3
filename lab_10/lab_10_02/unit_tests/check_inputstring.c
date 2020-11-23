#include "check_main.h"

START_TEST(tests_input_out)
{
    FILE *f;
    f = fopen("unit_tests/f4.txt", "r");
    if (f)
    {
        node_t *list = NULL;
        int rc = inputstring(f, &list);
        ck_assert_int_eq(rc, OK);
        ck_assert_int_eq(list->string[0], 'o');
        ck_assert_int_eq(list->string[1], 'u');
        ck_assert_int_eq(list->string[2], 't');
        fclose(f);
        listfree(list);
    }
}
END_TEST

START_TEST(tests_input_cat)
{
    FILE *f;
    f = fopen("unit_tests/f5.txt", "r");
    if (f)
    {
        node_t *list = NULL;
        int rc = inputstring(f, &list);
        ck_assert_int_eq(rc, OK);
        ck_assert_int_eq(list->string[0], 'c');
        ck_assert_int_eq(list->string[1], 'a');
        ck_assert_int_eq(list->string[2], 't');
        fclose(f);
        listfree(list);
    }
}
END_TEST

START_TEST(tests_input_sps)
{
    FILE *f;
    f = fopen("unit_tests/f6.txt", "r");
    if (f)
    {
        node_t *list = NULL;
        int rc = inputstring(f, &list);
        ck_assert_int_eq(rc, OK);
        ck_assert_int_eq(list->string[0], 's');
        ck_assert_int_eq(list->string[1], 'p');
        ck_assert_int_eq(list->string[2], 's');
        fclose(f);
        listfree(list);
    }
}
END_TEST

START_TEST(tests_input_pos)
{
    FILE *f;
    f = fopen("unit_tests/f7.txt", "r");
    if (f)
    {
        node_t *list = NULL;
        int rc = inputstring(f, &list);
        ck_assert_int_eq(rc, OK);
        ck_assert_int_eq(list->string[0], 'p');
        ck_assert_int_eq(list->string[1], 'o');
        ck_assert_int_eq(list->string[2], 's');
        fclose(f);
        listfree(list);
    }
}
END_TEST

START_TEST(tests_input_none)
{
    FILE *f;
    f = fopen("unit_tests/f3.txt", "r");
    if (f)
    {
        node_t *list = NULL;
        int rc = inputstring(f, &list);
        ck_assert_int_eq(rc, INPUTERROR);
        ck_assert_ptr_eq(list, NULL);
        fclose(f);
        listfree(list);
    }
}
END_TEST

START_TEST(tests_input_error)
{
    FILE *f;
    f = fopen("unit_tests/f8.txt", "r");
    if (f)
    {
        node_t *list = NULL;
        int rc = inputstring(f, &list);
        ck_assert_int_eq(rc, OK);
        ck_assert_int_eq(list->string[0], 'q');
        ck_assert_int_eq(list->string[1], 'w');
        ck_assert_int_eq(list->string[2], 'e');
        ck_assert_int_eq(list->string[3], 'e');
        fclose(f);
        listfree(list);
    }
}
END_TEST

START_TEST(tests_input_error1)
{
    FILE *f;
    f = fopen("unit_tests/f1.txt", "r");
    if (f)
    {
        node_t *list = NULL;
        int rc = inputstring(f, &list);
        ck_assert_int_eq(rc, OK);
        ck_assert_int_eq(list->string[0], 'I');
        ck_assert_int_eq(list->string[1], ' ');
        ck_assert_int_eq(list->string[2], 'l');
        ck_assert_int_eq(list->string[3], 'o');
        fclose(f);
        listfree(list);
    }
}
END_TEST

START_TEST(tests_input_error2)
{
    FILE *f;
    f = fopen("unit_tests/f2.txt", "r");
    if (f)
    {
        node_t *list = NULL;
        int rc = inputstring(f, &list);
        ck_assert_int_eq(rc, OK);
        ck_assert_str_eq(list->string, "s");
        fclose(f);
        listfree(list);
    }
}
END_TEST


Suite* inputstring_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("inputstring");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_input_out);
    tcase_add_test(tc_pos, tests_input_cat);
    tcase_add_test(tc_pos, tests_input_sps);
    tcase_add_test(tc_pos, tests_input_pos);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, tests_input_none);
    tcase_add_test(tc_neg, tests_input_error);
    tcase_add_test(tc_neg, tests_input_error1);
    tcase_add_test(tc_neg, tests_input_error2);
    suite_add_tcase(s, tc_neg);

    return s;
}
