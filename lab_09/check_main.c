#include "check_main.h"

int main(void)
{
    int no_failed = 0;

    SRunner *runner;

    runner = srunner_create(film_read_suite());
    srunner_add_suite(runner, film_init_suite());
    srunner_add_suite(runner, film_copy_suite());
    srunner_add_suite(runner, f_count_suite());
//    srunner_add_suite(runner, f_create_suite());
    srunner_add_suite(runner, f_read_suite());
    srunner_add_suite(runner, film_found_suite());
    srunner_add_suite(runner, my_check_feild_suite());
    srunner_add_suite(runner, my_check_key_suite());


    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
