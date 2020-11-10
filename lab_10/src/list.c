#include "list.h"


node_t* listcreatenode(void* data)
{
    node_t *elem = NULL;

    elem = malloc(sizeof(node_t));

    if (elem)
    {
        elem->data = data;
        elem->next = NULL;
    }
    else
    {
        elem = NULL;
    }

    return elem;
}

node_t* listaddbegin(node_t* head, node_t* node)
{
    node->next = head;
    return node;
}

static int filelen(FILE *f)
{
    int num, len = 0;
    rewind(f);
    while(fscanf(f, "%d", &num) == 1)
    {
        len++;
    }

    return len;
}
node_t* listread(FILE *f, int **num1)
{
    node_t *head = NULL, *node = NULL;
    
    int len = filelen(f);
    rewind(f);
    if (len == 0)
    {
        return NULL;
    }

    *num1 = malloc(len * sizeof(int));
    int *num = *num1;
    for (int i = 0; i < len; i++)
    {
        fscanf(f, "%d", num);
        node = listcreatenode((void *)num);
        if (node)
        {
            head = listaddbegin(head, node);
            num++;
        }
        else
        {
            listfree(head);
            free(num);
        }
    }
    return head;
}

void listfree(node_t *head)
{
    node_t *next = NULL;

    while(head)
    {
        next = head;
        head = head->next;
        free(next);
    }
}

void listprint(FILE *f, node_t *head)
{
    node_t *cur = head;
    while (cur != NULL)
    {
        fprintf(f, "%d\n", *((int *)cur->data));
        cur = cur->next;
    }
}
