#include "task_02.h"

int copy(node_t *head, node_t **new_head)
{
    node_t *cur = head;
    if (head == NULL)
    {
        *new_head = NULL;
        return INVALID_ARG;
    }
    else
    {
        node_t *new_list = malloc(sizeof(node_t));
        if (new_list)
        {
            new_list->data = cur->data;
            copy(cur->next, &new_list->next);
            *new_head = new_list;

            return OK;
        }
        else
        {
            *new_head = NULL;

            return MEMERROR;
        }
    }
	
    return OK;
}

node_t *reverse(node_t *head)
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

void remove_duplicates(node_t **head, int (*comparator)(const void *, const void *))
{
    if (!head || !(*head))
    {
        return;
    }

    node_t *tmp = *head;
    node_t *tmp_1;

    for (; tmp && tmp->next;)
    {
        tmp_1 = tmp->next;

        if (comparator(tmp->data, tmp_1->data) == 0)
        {
            tmp->next = tmp_1->next;
            tmp_1->next = NULL;
            free(tmp_1);
        }
        else
        {
            tmp = tmp->next;
        }
    }
}
