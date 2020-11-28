#ifndef _TASK_01_H
#define _TASK_01_H

#include "app.h"

node_t *find(node_t *head, const void *data, int (*comparator)(const void*, const void*));

void *pop_front(node_t **head);

void *pop_back(node_t **head);

void insert(node_t **head, node_t *elem, node_t *before);

#endif // _TASK_01_H
