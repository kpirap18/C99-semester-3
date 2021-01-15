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


void print_list(FILE *f, node_t *head)
{
    node_t *cur = head;

    while (cur != NULL)
    {
        fprintf(f, "%d ", cur->data);
        cur = cur->next;
    }
}


int create_node(node_t **elem, int data)
{
    int rc = OK;
    *elem = malloc(sizeof(node_t));

    if (*elem)
    {
        (*elem)->data = data;
        (*elem)->next = NULL;
    }
    else
    {
        rc = MEMORYERR;
    }

    return rc;
}