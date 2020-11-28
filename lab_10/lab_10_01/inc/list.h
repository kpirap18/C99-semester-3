#ifndef _LIST_H_
#define _LIST_H_

#define _GNU_SOURCE

#include "app.h"

node_t *readdata(FILE *f);

node_t *listonefree(node_t *node);

void freebook(book_r *del);

node_t *listcreatenode(char *name, char *author);

node_t *listaddbegin(node_t *head, node_t *node);

#endif // _LIST_H_