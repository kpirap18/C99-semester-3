#include "../inc/check_main.h"

START_TEST(tests_found_name)
{
    film_r films[3] = {{ "Awerty", "aaaaa", 12},
                       { "Dasdff", "dfdfaa", 512},
                       { "Okmnj", "ldfda", 128}};
    int rc;

    rc = film_found(films, "name", "ldfda", 3);
    ck_assert_int_eq(rc, 2);
}
END_TEST

START_TEST(tests_found_title)
{
    film_r films[3] = {{ "Awerty", "aaaaa", 12},
                       { "Dasdff", "dfdfaa", 512},
                       { "Okmnj", "ldfda", 128}};
    int rc;

    rc = film_found(films, "title", "Awerty", 3);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_found_year)
{
    film_r films[3] = {{ "Qwerty", "aaaaa", 12},
                       { "Dasdff", "dfdfaa", 512},
                       { "Okmnj", "adfda", 128}};
    int rc;

    rc = film_found(films, "year", "512", 3);
    ck_assert_int_eq(rc, 1);
}
END_TEST

START_TEST(tests_found_name_not)
{
    film_r films[3] = {{ "Qwerty", "aaaaa", 12},
                       { "Dasdff", "dfdfaa", 512},
                       { "Okmnj", "adfda", 128}};
    int rc;

    rc = film_found(films, "name", "ddddd", 3);
    ck_assert_int_eq(rc, NOT_FOUND);
}
END_TEST

START_TEST(tests_found_title_not)
{
    film_r films[3] = {{ "Qwerty", "aaaaa", 12},
                       { "Dasdff", "dfdfaa", 512},
                       { "Okmnj", "adfda", 128}};
    int rc;

    rc = film_found(films, "title", "ddddd", 3);
    ck_assert_int_eq(rc, NOT_FOUND);
}
END_TEST

START_TEST(tests_found_year_not)
{
    film_r films[3] = {{ "Qwerty", "aaaaa", 12},
                       { "Dasdff", "dfdfaa", 512},
                       { "Okmnj", "adfda", 128}};
    int rc;

    rc = film_found(films, "year", "1111", 3);
    ck_assert_int_eq(rc, NOT_FOUND);
}
END_TEST

Suite* film_found_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("film_found");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_found_name);
    tcase_add_test(tc_pos, tests_found_title);
    tcase_add_test(tc_pos, tests_found_year);
    tcase_add_test(tc_pos, tests_found_name_not);
    tcase_add_test(tc_pos, tests_found_title_not);
    tcase_add_test(tc_pos, tests_found_year_not);
    suite_add_tcase(s, tc_pos);

    return s;
}
