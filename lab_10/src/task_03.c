#include "task_03.h"
#include "list.h"

#define EPS 1e-6

node_t* sort(node_t *head, int (*comparator)(const void *, const void *))
{
    if (!head || !head->next)
    {
        return head;
    }

    if (!comparator)
    {
        return 0;
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

void front_back_split(node_t* head, node_t** back)
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

node_t* sorted_merge(node_t** head_a, node_t** head_b, int (*comparator)(const void *, const void *))
{
    if (!comparator || !head_a || !head_b)
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

int comparator_int(const void *p, const void *q)
{
    const int *a = p;
    const int *b = q;
    return *a - *b;
}

int comparator_char(const void *p, const void *q)
{
    const char *a = p;
    const char *b = q;
    return *a - *b;
}

int comparator_double(const void *p, const void *q)
{
    const double *a = p;
    const double *b = q;
    if (fabs(*a - *b) < EPS)
        return 0;
    else if (*a - *b > EPS)
        return 1;
    else 
        return -1;
}
