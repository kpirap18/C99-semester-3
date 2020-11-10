#include "task_02.h"

node_t* reverse(node_t *head)
{
    node_t *new_head = NULL;
    node_t *next = NULL;

    while (head)
    {
        next = head->next;
        head->next = new_head;
        new_head = head;
        head = next;
    }

    return new_head;
}
