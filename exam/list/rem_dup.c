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
