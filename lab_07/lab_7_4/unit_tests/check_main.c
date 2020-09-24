#include "../inc/check_main.h"

int main(void)
{
    int no_failed = 0;
    Suite *s1, *s2, *s3, *s4, *s5, *s6, *s7, *s8, *s9;
    SRunner *runner;

    s1 = avarage_suite();
    s2 = compare_suite();
    s3 = file_size_suite();
    s4 = key_suite();
    s5 = key_count_suite();
    s6 = mysort_suite();
    s7 = parsing_array_suite();
    s8 = parsing_key_array_suite();
    s9 = swap_suite();

    runner = srunner_create(s1);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);

    runner = srunner_create(s2);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);

    runner = srunner_create(s3);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);

    runner = srunner_create(s4);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);

    runner = srunner_create(s5);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);

    runner = srunner_create(s6);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);

    runner = srunner_create(s7);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);

    runner = srunner_create(s8);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);

    runner = srunner_create(s9);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
