#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <math.h>
#include <sys/types.h>

#define OK           0
#define POPERROR    -1
#define INSERTERROR -2
#define SORTERROR   -3
#define REVERROR    -4
#define NOTALLARG   -5
#define OPENERROR   -6
#define INVALID_ARG -7
#define MEMERROR    -8

typedef struct node
{
    int data;
    struct node *next;
} node_t;

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
// после
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
        if (tmp == before)
        {
            elem->next = before->next;
            before->next = elem;
            break;
        }
        tmp = tmp->next;
    }
}
// перед
void insert2(node_t **head, node_t *elem, node_t *before) 
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

node_t *listaddbegin(node_t *list, node_t *node)
{
    node->next = list;
    return node;
}

void add_end(node_t **head, node_t *elem)
{
    node_t *tmp = *head;
    if (*head == NULL)
    {
        elem->next = NULL;
        *head = elem;
    }

    while (tmp)
    {
        if (tmp->next == NULL)
        {
            elem->next = NULL;
            tmp->next = elem;
            break;
        }
        tmp = tmp->next;
    }
}


node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    if (!head || !head->next)
    {
        return head;
    }

    if (!comparator)
    {
        return NULL;
    }

    node_t *a = NULL;
    node_t *b = NULL;
    node_t *back = NULL;
    node_t *new_head = NULL;

    front_back_split(head, &back);
    a = sort(head, comparator);
    b = sort(back, comparator);

    new_head = sorted_merge(&a, &b, comparator);

    return new_head;
}

void front_back_split(node_t *head, node_t **back)
{
    if (!head || !back)
    {
        return;
    }

    node_t *b = head;

    while (head->next && head->next->next)
    {
        b = b->next;
        head = head->next->next;
    }

    *back = b->next;
    b->next = NULL;
}

node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *))
{
    if (!head_a || !head_b)
    {
        return NULL;
    }
	
    if (comparator == NULL)
    {
        return NULL;
    }

    node_t *a = *head_a;
    node_t *b = *head_b;
    node_t *head = NULL;
    node_t *c = NULL;

    if (a || b)
    {
        if (!b || (a && comparator(a->data, b->data) < 0))
        {
            head = a;
            c = head;
            a = a->next;
        }
        else if (b)
        {
            head = b;
            c = head;
            b = b->next;
        }
    }

    while (a && b)
    {
        if (comparator(a->data, b->data) < 0)
        {
            c->next = a;
            c = c->next;
            a = a->next;
        }
        else
        {
            c->next = b;
            c = c->next;
            b = b->next;
        }
    }

    while (a)
    {
        c->next = a;
        c = c->next;
        a = a->next;
    }

    while (b)
    {
        c->next = b;
        c = c->next;
        b = b->next;
    }

    a = NULL;
    b = NULL;
    c = NULL;
    *head_a = NULL;
    *head_b = NULL;

    return head;
}
