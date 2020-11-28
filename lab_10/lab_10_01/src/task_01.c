#include "task_01.h"

node_t *find(node_t *head, const void *data, int (*comparator)(const void*, const void*))
{
    node_t *tmp = head;
    int *cur = NULL;
    const int *search = data;

    for (; tmp != NULL; tmp = tmp->next)
    {
        cur = tmp->data;

        if (comparator(cur, search) == 0)
        {
            return tmp;
        }
    }

    return NULL;
}

void *pop_front(node_t **head)
{
    if (!head || !(*head))
    {
        return NULL;
    }

    node_t *buf = *head;
    void *data = buf->data;
    *head = buf->next;
    free(buf);
    
    return data;
}

void *pop_back(node_t **head)
{
    if (!head || !(*head))
    {
        return NULL;
    }
    
    void *data = NULL;

    node_t *tmp = *head;
    if (tmp)
    {
        if (tmp->next)
        {
            for (; tmp->next->next; tmp = tmp->next);
            data = tmp->next->data;
            free(tmp->next);
            tmp->next = NULL;
        }
        else
        {
            data = tmp->data;
            free(tmp);
            *head = NULL;
        }
    }

    return data;
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
