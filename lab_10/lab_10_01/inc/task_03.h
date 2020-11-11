#ifndef TASK_03_H
#define TASK_03_H

#include "app.h"

node_t* sort(node_t *head, int (*comparator)(const void *, const void *));

void front_back_split(node_t* head, node_t** back);

node_t* sorted_merge(node_t** head_a, node_t** head_b, int (*comparator)(const void *, const void *));

int comparator_int(const void *p, const void *q);

int comparator_char(const void *p, const void *q);

int comparator_double(const void *p, const void *q);

#endif // TASK_03_H
