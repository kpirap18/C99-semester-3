#include "check_main.h"

int main(void)
{
    int no_failed = 0;

    SRunner *runner;

    runner = srunner_create(count_suite());
    srunner_add_suite(runner, isdelim_suite());
    srunner_add_suite(runner, checkfile_suite());

    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
