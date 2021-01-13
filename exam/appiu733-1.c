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

int input_number(FILE *f, int *number)
{
    int rc = OK;

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

int in_list(node_t **head, int number)
{
    int data, rc = OK;
    node_t *elem = NULL;

    if (number < 0)
    {
        number *= -1;
    }
    
    if (number == 0)
    {
        rc = create_node(elem, number);
        if (rc == OK)
        {
            add_begin(*head, elem);
        }
    }

    while (number > 0)
    {
        data = number % 10;
        rc = create_node(&elem, data);
        if (rc == OK)
        {
            *head = add_begin(*head, elem);
            number /= 10;
        }
        else
            break;
    }

    return rc;
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

int main()
{
    int rc = OK, number;
    node_t *head = NULL;

    rc = input_number(stdin, &number);
    if (rc != OK)
    {
        return INPUTERR;
    }

    head = in_list(head, number);

    print_list(stdout, head);

    free_list(head);

    return rc;
}


