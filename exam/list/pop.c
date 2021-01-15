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