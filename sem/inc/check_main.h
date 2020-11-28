#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#include <stdlib.h>
#include <check.h>
#include "count.h"
#include "mycheck.h"

Suite* count_suite(void);

Suite* isdelim_suite(void);

Suite* checkfile_suite(void);

#endif // CHECK_MAIN_H
