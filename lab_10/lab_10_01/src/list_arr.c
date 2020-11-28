#include "list.h"
#include "list_arr.h"
#include "task_02.h"

node_t *listread(FILE *f)
{
    int flag = 0;
    node_t *head = NULL, *node = NULL;
    
    while ((!feof(f)) && (flag == 0))
    {
        node = readdata(f);
        if (node)
        {
            if (head == NULL)
            {
                head = node;
            }
            else
            {
                head = listaddbegin(head, node);
            }
        }
        else if ((fgetc(f) != '\n') && (!feof(f)))
        {
            flag = -1;
            listfree(head);
            head = NULL;
        }
    }
    if (flag == 0)
        head = reverse(head);
    
    return head;
}

void listfree(node_t *head)
{
    node_t *next = NULL;

    while (head)
    {
        next = head;
        head = listonefree(next);
    }
}

void listprint(FILE *f, node_t *head)
{
    node_t *cur = head;
    while (cur != NULL)
    {
        fprintf(f, "%s\n", ((book_r*)(cur->data))->name);
        fprintf(f, "%s\n", ((book_r *)(cur->data))->author);
        cur = cur->next;
    }
}