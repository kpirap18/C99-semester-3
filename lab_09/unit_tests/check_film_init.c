#include "../inc/check_main.h"

START_TEST(tests_usual)
{
    film_r film = { NULL, NULL, 0};
    int rc;

    rc = film_init(&film, "Qwerty", "Assdfg", 1234);
    ck_assert_int_eq(rc, OK);

    film_free_one(&film);
}
END_TEST

Suite* film_init_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("film_init");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_usual);
    suite_add_tcase(s, tc_pos);

    return s;
}
