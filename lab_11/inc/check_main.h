#ifndef _CHECK_MAIN_H_
#define _CHECK_MAIN_H_

#include <stdlib.h>
#include <check.h>
#include <stdio.h>
#include <limits.h>
#include "my_snprintf.h"
#include "func.h"

Suite* my_snprintf_suite(void);

Suite* my_strlen_suite(void);

Suite* lennumber_suite(void);

Suite* leninsystem_suite(void);

Suite* inttostring_suite(void);

Suite* toanysystem_suite(void);

#endif // _CHECK_MAIN_H_
