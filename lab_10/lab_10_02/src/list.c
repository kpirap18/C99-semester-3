#include "list.h"

node_t *listcreatenode(char *string, int *pos, int *len)
{
    node_t *elem = NULL;

    elem = malloc(sizeof(node_t));

    if (elem)
    {
        for (int i = 0; i < LENSTATICSTR; ++i)
        {
            elem->string[i] = '\0';
        }
        if (*len >= LENSTATICSTR)
        {
            for (int i = 0; i < LENSTATICSTR; ++i, ++(*pos))
            {
                elem->string[i] = string[*pos];
            }
            *len -= LENSTATICSTR;
        }
        else
        {
            for (int i = 0; i < *len; ++i, ++(*pos))
            {
                elem->string[i] = string[*pos];
            }
            *len = 0;
        }
        elem->next = NULL;
    }
    else
    {
        elem = NULL;
    }

    return elem;
}

node_t *listaddbegin(node_t *list, node_t *node)
{
    node->next = list;
    return node;
}

node_t *reverse(node_t *list)
{
    node_t *new_list = NULL;
    node_t *next = NULL;

    while (list)
    {
        next = list->next;
        list->next = new_list;
        new_list = list;
        list = next;
    }

    return new_list;
}

void append(node_t **list1, node_t **list2)
{
    if ((*list1) == NULL || list1 == NULL || (*list2) == NULL || list2 == NULL)
    {
        return;
    }
    node_t *tmp = *list1;

    while (tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = *list2;

    *list2 = NULL;
}

void listfree(node_t *list)
{
    node_t *next = NULL;

    while (list)
    {
        next = list;
        list = list->next;
        free(next);
    }
}

void listcount(node_t *list, int *count)
{
    while (list)
    {
        (*count)++;
        list = list->next;
    }
}
