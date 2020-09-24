#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#include <stdlib.h>
#include <check.h>
#include "main.h"
#include "mysort.h"
#include "parsing.h"
#include "key.h"

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
