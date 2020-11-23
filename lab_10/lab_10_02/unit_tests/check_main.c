#include "check_main.h"

int main(void)
{
    int no_failed = 0;

    SRunner *runner;

    runner = srunner_create(my_getline_suite());
    srunner_add_suite(runner, inputcommand_suite());
    srunner_add_suite(runner, inputstring_suite());
    srunner_add_suite(runner, stringtolist_suite());
    srunner_add_suite(runner, mycheckcommand_suite());
    srunner_add_suite(runner, findpos_suite());
    srunner_add_suite(runner, deletespice_suite());
    srunner_add_suite(runner, listcount_suite());
    srunner_add_suite(runner, append_suite());
    srunner_add_suite(runner, reverse_suite());
    srunner_add_suite(runner, listcreatenode_suite());
    srunner_add_suite(runner, listaddbegin_suite());

    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
