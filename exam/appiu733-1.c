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

int input_number(FILE *f, int *number);
node_t *in_list(node_t *head, int number);
node_t *create_node(int data);
node_t *add_begin(node_t *head, node_t *node);
void print_list(FILE *f, node_t *head);
void free_list(node_t *head);

int main()
{
    int rc = OK, number;
    node_t *head = NULL;

    rc = input_number(stdin, &number);
    if (rc != OK)
    {
        printf("Input error\n");
    }

    head = in_list(head, number);

    print_list(stdout, head);

    free_list(head);

    return rc;
}

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

node_t *create_node(int data)
{
    node_t *elem = malloc(sizeof(node_t));

    if (elem)
    {
        elem->data = data;
        elem->next = NULL;
    }
    else
    {
        return NULL;
    }

    return elem;
}

node_t *add_begin(node_t *head, node_t *node)
{
    node->next = head;
    return node;
}

node_t *in_list(node_t *head, int number)
{
    int data;
    node_t *elem = NULL;

    if (number < 0)
    {
        number *= -1;
    }
    if (number == 0)
    {
        elem = create_node(number);
        add_begin(head, elem);
    }
    while (number > 0)
    {
        data = number % 10;
        elem = create_node(data);
        add_begin(head, elem);
        number /= 10;
    }

    return head;
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
    node_t *cur = head;

    for ( ; head; head = cur)
    {
        cur = head->next;
        free(head);
    }
}
