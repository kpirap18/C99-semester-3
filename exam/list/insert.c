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