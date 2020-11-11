#ifndef LIST_H
#define LIST_H

#include "app.h"
#include "my_check.h"

node_t* listcreatenode(void* data);

node_t* listaddbegin(node_t* head, node_t* node);

node_t* listread(FILE *f, int **num);

void listfree(node_t *head);

void listprint(FILE *f, node_t *head);

#endif // LIST_H
