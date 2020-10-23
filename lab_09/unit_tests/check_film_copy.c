#include "../inc/check_main.h"

START_TEST(tests_usual)
{
    film_r film_to = { NULL, NULL, 0};
    film_r film_from = { "Qwerty", "asdfg", 1234};
    int rc;

    rc = film_copy(&film_to, &film_from);
    ck_assert_int_eq(rc, OK);

    film_free_one(&film_to);
}
END_TEST

Suite* film_copy_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("film_copy");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_usual);
    suite_add_tcase(s, tc_pos);

    return s;
}
