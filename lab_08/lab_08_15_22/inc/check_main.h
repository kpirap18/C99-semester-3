#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#include <stdlib.h>
#include <check.h>
#include "initializmatrix.h"
#include "operationmatrix.h"
#include "io.h"

Suite* null_matrix_suite(void);

Suite* null_one_matrix_suite(void);

Suite* sum_matrix_suite(void);

Suite* multi_matrix_suite(void);

Suite* read_matrix_suite(void);

Suite* read_info_mat_suite(void);

#endif // CHECK_MAIN_H
