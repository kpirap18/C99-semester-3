#include "check_main.h"

void* pop_back(node_t **head);

void insert(node_t **head, node_t *elem, node_t *before);

node_t *find(node_t *head, const void *data, int (*comparator)(const void*, const void*));