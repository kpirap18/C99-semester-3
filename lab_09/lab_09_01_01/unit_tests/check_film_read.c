#include "check_main.h"

START_TEST(tests_usual)
{
    film_r film = { NULL, NULL, 0};
    FILE *f = fopen("func_tests/f1.txt","r");
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
    film_r film = { NULL, NULL, 0};
    FILE *f = fopen("func_tests/f2.txt","r");
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

START_TEST(tests_empty_title)
{
    film_r film = { NULL, NULL, 0};
    FILE *f = fopen("func_tests/f3.txt","r");
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

START_TEST(tests_let_year)
{
    film_r film = { NULL, NULL, 0};
    FILE *f = fopen("func_tests/f4.txt","r");
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

START_TEST(tests_films_read)
{
    film_r *film = calloc(1, sizeof(film_r));
    FILE *f = fopen("func_tests/f1.txt","r");
    int rc;

    if (f)
    {
        rc = f_read(f, film, 1, "name");
        ck_assert_int_eq(rc, OK);
        fclose(f);
    }
    f_free(film, 1);
}
END_TEST

START_TEST(tests_films_create)
{
    film_r *film = NULL;
    FILE *f = fopen("func_tests/f1.txt","r");
	int n;
    int rc;

    if (f)
    {
        rc = f_create(f, &film, &n, "name");
        ck_assert_int_eq(rc, OK);
		ck_assert_int_eq(n, 1);
        fclose(f);
    }
    f_free(film, 1);
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

Suite* f_read_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("f_read");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_films_read);
    suite_add_tcase(s, tc_pos);

    return s;
}

Suite* f_create_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("f_create");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_films_create);
    suite_add_tcase(s, tc_pos);

    return s;
}
