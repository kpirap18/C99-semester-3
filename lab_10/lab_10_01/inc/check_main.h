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

Suite* comparator_suite(void);

Suite* reverse_suite(void);

Suite* pop_suite(void);

Suite* sort_suite(void);

Suite* my_check_key_suite(void);

Suite* find_suite(void);

Suite* filelen_suite(void);

Suite* insert_suite(void);

Suite* listcreatenode_suite(void);

Suite* listread_suite(void);

Suite* listaddbegin_suite(void);

#endif // CHECK_MAIN_H
