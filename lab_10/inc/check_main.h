#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#include <stdlib.h>
#include <check.h>
#include "list.h"
#include "task_01.h"
#include "task_02.h"
#include "task_03.h"
#include "my_check.h"

#define OK           0
#define POPERROR    -1
#define INSERTERROR -2
#define SORTERROR   -3
#define REVERROR    -4
#define NOTALLARG   -5
#define OPENERROR   -6
#define INVALID_ARG -7

Suite* avarage_suite(void);
Suite* compare_suite(void);
Suite* file_size_suite(void);
Suite* key_suite(void);
Suite* key_count_suite(void);
Suite* mysort_suite(void);
Suite* parsing_array_suite(void);
Suite* parsing_key_array_suite(void);
Suite* swap_suite(void);

#endif // CHECK_MAIN_H
