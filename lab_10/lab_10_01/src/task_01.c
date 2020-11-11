#include "task_01.h"

void* pop_back(node_t **head)
{
    node_t *end = NULL;
    if (*head != NULL)
    {
        node_t *cur = *head;
        if (cur->next)
        {
            for ( ; cur->next->next; cur = cur->next)
                ;
            end = cur->next;
            cur->next = NULL;
        }
        else
        {
            end = cur;
            *head = NULL;
        }
    }

    return end;
}

void insert(node_t **head, node_t *elem, node_t *before) 
{
    node_t *tmp = *head;
    
    if (!head)
    {
        if (!before)
        {
            *head = elem;
        }
    }
    else if (*head == before)
    {
        elem->next = before;
        *head = elem;
    }
    
    while (tmp)
    {
        if (tmp->next == before)
        {
            elem->next = before;
            tmp->next = elem;
            break;
        }
        tmp = tmp->next;
    }
}

node_t *find(node_t *head, const void *data, int (*comparator)(const void*, const void*))
{
    node_t *tmp = head;
    int *cur = NULL;
    const int *search = data;

    for ( ; tmp != NULL; tmp = tmp->next)
    {
        cur = tmp->data;

        if (comparator(cur, search) == 0)
        {
            return tmp;
        }
    }

    return NULL;
}