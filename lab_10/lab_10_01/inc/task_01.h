#ifndef TASK_01_H
#define TASK_01_H

#include "app.h"

void* pop_back(node_t **head);

void insert(node_t **head, node_t *elem, node_t *before);

node_t *find(node_t *head, const void *data, int (*comparator)(const void*, const void*));

#endif // TASK_01_H
