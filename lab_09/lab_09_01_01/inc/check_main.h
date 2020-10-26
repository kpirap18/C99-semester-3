#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#include <stdlib.h>
#include <check.h>
#include "my_check.h"
#include "film_arr.h"
#include "film.h"
#include "app.h"

Suite* film_read_suite(void);

Suite* film_init_suite(void);

Suite* film_copy_suite(void);

Suite* f_count_suite(void);

Suite* f_create_suite(void);

Suite* f_read_suite(void);

Suite* film_found_suite(void);

Suite* my_check_feild_suite(void);

Suite* my_check_key_suite(void);

Suite* f_create_suite(void);

Suite* f_read_suite(void);

#endif // CHECK_MAIN_H
