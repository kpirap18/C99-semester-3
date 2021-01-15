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

