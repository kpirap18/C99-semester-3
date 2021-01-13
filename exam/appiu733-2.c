#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define MEMORYERR -1
#define INPUTERR -2

typedef struct node
{
    int data;
    struct node *next;
} node_t;

void free_list(node_t *head)
{
    node_t *next = NULL;

    while (head)
    {
        next = head;
        head = head->next;
        free(next);
    }
}

void print_list(FILE *f, node_t *head)
{
    node_t *cur = head;

    while (cur)
    {
        fprintf(f, "%d ", cur->data);
        cur = cur->next;
    }
}

int input_number(FILE *f, int *number)
{
    int rc;

    rc = fscanf(f, "%d", number);
    if (rc != 1)
    {
        printf("Input error\n");
        return INPUTERR;
    }

    return OK;
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

node_t *add_begin(node_t *head, node_t *node)
{
    node->next = head;
    return node;
}

int in_list(FILE *f, node_t **head)
{
    int number = 0;
    int rc = OK;
    node_t *elem = NULL;

    rc = input_number(f, &number);
    if (rc == INPUTERR || number == 0)
    {
        return rc;
    }
    
    while (number != 0 && rc == OK)
    {
        rc = create_node(&elem, number);
        if (rc == MEMORYERR)
        {
            free_list(*head);
            *head = NULL;
            break;
        }
        *head = add_begin(*head, elem);
        rc = input_number(f, &number);
        if (rc == INPUTERR)
        {
            free_list(*head);
        }
    }

    return rc;
}

int main()
{
    int rc = OK;
    node_t *head = NULL;
    rc = in_list(stdin, &head);
    if (rc == OK)
    {
        print_list(stdout, head);
        free_list(head);
    }

    return rc;
}
