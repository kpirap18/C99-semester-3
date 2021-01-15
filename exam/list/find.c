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