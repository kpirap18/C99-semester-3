#ifndef _LISTARR__H
#define _LISTARR__H

#include "app.h"

node_t *listread(FILE *f);

void listfree(node_t *head);

void listprint(FILE *f, node_t *head);

#endif // _LISTARR__H
