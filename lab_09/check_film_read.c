#include "check_main.h"

START_TEST(tests_usual)
{
    film_r film;
    FILE *f = fopen("C:/msys64/home/Ira/cprog/lab_09/unit_tests/f1.txt","r");
    int rc;

    if (f)
    {
        rc = film_read(f, &film);
        ck_assert_int_eq(rc, OK);
        fclose(f);
    }
    film_free_one(&film);
}
END_TEST

START_TEST(tests_empty_name)
{
    film_r film;
    FILE *f = fopen("C:/msys64/home/Ira/cprog/lab_09/unit_tests/f2.txt","r");
    int rc;

    if (f)
    {
        rc = film_read(f, &film);
        ck_assert_int_eq(rc, FILE_INVALID_ARG);
        fclose(f);
    }
    film_free_one(&film);
}
END_TEST

START_TEST(tests_empty_title)
{
    film_r film;
    FILE *f = fopen("C:/msys64/home/Ira/cprog/lab_09/unit_tests/f3.txt","r");
    int rc;

    if (f)
    {
        rc = film_read(f, &film);
        ck_assert_int_eq(rc, FILE_INVALID_ARG);
        fclose(f);
    }
    film_free_one(&film);
}
END_TEST

START_TEST(tests_let_year)
{
    film_r film;
    FILE *f = fopen("C:/msys64/home/Ira/cprog/lab_09/unit_tests/f4.txt","r");
    int rc;

    if (f)
    {
        rc = film_read(f, &film);
        ck_assert_int_eq(rc, FILE_INVALID_ARG);
        fclose(f);
    }
    film_free_one(&film);
}
END_TEST

Suite* film_read_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("film_read");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, tests_let_year);
    tcase_add_test(tc_neg, tests_empty_title);
    tcase_add_test(tc_neg, tests_empty_name);
    suite_add_tcase(s, tc_neg);


    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_usual);
    suite_add_tcase(s, tc_pos);

    return s;
}

