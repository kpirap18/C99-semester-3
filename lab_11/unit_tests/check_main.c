#include "check_main.h"

int main(void)
{
    int no_failed = 0;

    SRunner *runner;

    runner = srunner_create(my_snprintf_suite());
    srunner_add_suite(runner, my_strlen_suite());
    srunner_add_suite(runner, lennumber_suite());
    srunner_add_suite(runner, leninsystem_suite());
    srunner_add_suite(runner, inttostring_suite());
    srunner_add_suite(runner, toanysystem_suite());

    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
