#include "check_main.h"

int main(void)
{
    int no_failed = 0;

    SRunner *runner;

    runner = srunner_create(sort_suite());
    srunner_add_suite(runner, reverse_suite());
    srunner_add_suite(runner, comparator_suite());
    srunner_add_suite(runner, my_check_key_suite());
    srunner_add_suite(runner, pop_suite());
    srunner_add_suite(runner, find_suite());
    srunner_add_suite(runner, filelen_suite());
    srunner_add_suite(runner, insert_suite());
    srunner_add_suite(runner, listcreatenode_suite());
    srunner_add_suite(runner, listread_suite());
    srunner_add_suite(runner, listaddbegin_suite());

    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
