#ifndef _TASK_02_H
#define _TASK_02_H

#include "app.h"
#include "task_01.h"

int copy(node_t *head, node_t **new_head);

void remove_duplicates(node_t **head, int (*comparator)(const void *, const void *));

node_t *reverse(node_t *head);

#endif // _TASK_02_H
