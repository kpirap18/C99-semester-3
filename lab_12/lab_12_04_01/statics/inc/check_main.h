#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#include <stdlib.h>
#include <check.h>
#include "mysort.h"
#include "parsing.h"
#include "key.h"

#define OK 0
#define EPS 1e-6
#define ERROR -1
#define FILE_OPEN_ERR -2
#define FILE_EMPTY_ERR -3
#define KEYARRAY_EMRTY_ERR -4
#define INVALID_ARG -5
#define ERROR_MEMORY -6

Suite* avarage_suite(void);
Suite* compare_suite(void);
Suite* file_size_suite(void);
Suite* key_suite(void);
Suite* key_count_suite(void);
Suite* mysort_suite(void);
Suite* parsing_array_suite(void);
Suite* swap_suite(void);

#endif // CHECK_MAIN_H
