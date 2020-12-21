#include "check_main.h"

int main(void)
{
    int no_failed = 0;

    SRunner *runner;

    runner = srunner_create(avarage_suite());
    srunner_add_suite(runner, compare_suite());
    srunner_add_suite(runner, file_size_suite());
    srunner_add_suite(runner, key_suite());
    srunner_add_suite(runner, key_count_suite());
    srunner_add_suite(runner, mysort_suite());
    srunner_add_suite(runner, parsing_array_suite());
    srunner_add_suite(runner, swap_suite());


    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
