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

