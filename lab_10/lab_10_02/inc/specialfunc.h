#ifndef _MYCHECK_H_
#define _MYCHECK_H_

#include "io.h"
#include "app.h"
#include "list.h"
#include "parsing.h"

int mycheckcommand(char *feild);

void compact(node_t *list);

void deletespice(node_t *list);

int findpos(node_t *listwhere, node_t *listwhat);

#endif // _MYCHECK_H_