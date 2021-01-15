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
