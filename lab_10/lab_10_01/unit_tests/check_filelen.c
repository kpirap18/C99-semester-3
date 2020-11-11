#include "check_main.h"

START_TEST(tests_filelen)
{
    FILE *f;
    f = fopen("../func_tests/pos_01_in.txt", "r");
    if (f)
    {
        int len = filelen(f);
        ck_assert_int_eq(len, 7);
        fclose(f);
    }
}
END_TEST

START_TEST(tests_filelen_one)
{
    FILE *f;
    f = fopen("../func_tests/pos_02_in.txt", "r");
    if (f)
    {
        int len = filelen(f);
        ck_assert_int_eq(len, 1);
        fclose(f);
    }
}
END_TEST

START_TEST(tests_filelen_none)
{
    FILE *f;
    f = fopen("../func_tests/neg_01_in.txt", "r");
    if (f)
    {
        int len = filelen(f);
        ck_assert_int_eq(len, 0);
        fclose(f);
    }
}
END_TEST

Suite* filelen_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("filelen");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_filelen);
    tcase_add_test(tc_pos, tests_filelen_one);
    tcase_add_test(tc_pos, tests_filelen_none);
    suite_add_tcase(s, tc_pos);

    return s;
}
