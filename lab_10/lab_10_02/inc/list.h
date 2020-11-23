#ifndef _LIST_H_
#define _LIST_H_

#include "app.h"
#include "specialfunc.h"

node_t *listcreatenode(char *string, int *pos, int *len);

node_t *listaddbegin(node_t *list, node_t *node);

node_t *reverse(node_t *list);

void append(node_t **list1, node_t **list2);

void listfree(node_t *list);

void listcount(node_t *list, int *count);

#endif // _LIST_H_
