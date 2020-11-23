#ifndef _CHECK_MAIN_H_
#define _CHECK_MAIN_H_

#include <stdlib.h>
#include <check.h>
#include "list.h"
#include "my_getline.h"
#include "parsing.h"
#include "specialfunc.h"

#define OK              0
#define INPUTERROR     -1
#define COMMANDERROR   -2
#define NOTALLARG      -3
#define MEMERROR       -4
#define NOTPOS         -5

Suite* my_getline_suite(void);

Suite* inputcommand_suite(void);

Suite* inputstring_suite(void);

Suite* stringtolist_suite(void);

Suite* mycheckcommand_suite(void);

Suite* findpos_suite(void);

Suite* deletespice_suite(void);

Suite* listcount_suite(void);

Suite* append_suite(void);

Suite* reverse_suite(void);

Suite* listcreatenode_suite(void);

Suite* listaddbegin_suite(void);

#endif // _CHECK_MAIN_H_
