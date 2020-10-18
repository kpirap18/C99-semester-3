#include "../inc/check_main.h"

int main(void)
{
    int no_failed = 0;

    SRunner *runner;

    runner = srunner_create(null_matrix_suite());
    srunner_add_suite(runner, null_one_matrix_suite());
    srunner_add_suite(runner, sum_matrix_suite());
    srunner_add_suite(runner, multi_matrix_suite());
    srunner_add_suite(runner, read_info_mat_suite());
    srunner_add_suite(runner, read_matrix_suite());

    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
