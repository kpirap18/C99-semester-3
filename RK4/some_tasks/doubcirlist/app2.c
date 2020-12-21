#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct list_node
{
    int num;
    struct list_node *prev;
    struct list_node *next;
}node_t;

struct list_node* create_node(int num)
{
    struct list_node *node = (struct list_node*) malloc(sizeof(struct list_node));
    if (node)
    {
        node->num = num;
        node->prev= NULL;
        node->next = NULL;
    }
    return node;
}
struct list_node* add_end(struct list_node *hlist, struct list_node *node)
{
    struct list_node *cur = hlist;
    if (!hlist)
        return node;
    
    while (cur->next) 
        cur= cur->next;  
    
    cur->next = node;
    node->prev= cur;
    node->next = NULL;

    return hlist;
}

struct list_node* add_front(struct list_node *hlist, struct list_node *node)
{
    node->next = hlist;
    hlist->prev = node;
    
    return node;
}

struct list_node* del_by_value(struct list_node *hlist, int val)
{
    struct list_node *cur = hlist, *del, *temp = NULL;
    while (cur)
    {
        if (cur->num == val)
        {
            del = cur;
            if (cur->prev) // Если удаляемый элемент не первый
            {
                temp->next = cur->next;
                if (cur->next)
                {
                    temp = cur->next;
                    temp->prev = cur->prev;
                }
                cur = cur->next;
            }
            else if (cur->next)
            {
                hlist = cur->next; // Следующий элемент становится первым
                cur = cur->next;
                cur->prev = NULL;
            }
            else // если ээлемент один (т е ничего нет ни next ни prev)
            {
                hlist = NULL;
                cur = NULL;
            }
            free(del);
        }
        else
        {
            temp = cur;
            cur = cur->next;
        }
    }

    return hlist;
}

struct list_node* ins_by_position(struct list_node *hlist, int val, int pos)
{
    struct list_node *temp = create_node(val);
    struct list_node *p, *cur = hlist;
    if (pos == 1)    // Вставка в начало списка
    {
        temp->next = hlist;
        temp->prev= NULL;
        return temp;
    }
    
    for(int i = 1; i < pos-1; i++) 
        cur = cur->next;

    if (cur->next) // Вставка в середину списка
    {
        p = cur->next;
        cur->next = temp;
        temp->prev= cur;
        temp->next = p;
        p->prev= temp;
    }
    else // Вставка в конец списка
    {
        cur->next = temp;
        temp->prev= cur;
        temp->next = NULL;
    }
    
    return hlist;
}

void free_all(struct list_node *hlist)
{
    struct list_node *next;
    for (; hlist; hlist = next)
    { 
        next = hlist->next;
        free(hlist);
    } 
    
    free(next);
}

int count(struct list_node *hlist)
{
    int counter = 0;
    if (!hlist)
        return 0;
    
    for (; hlist; hlist= hlist->next)
        counter++;
    
    return counter;
}

struct list_node* search(struct list_node *hlist, int num)
{
    for (; hlist; hlist= hlist->next)
        if (hlist->num == num)
            return hlist;
    
    return NULL;
}

void print_list(struct list_node *hlist)
{
    for (; hlist; hlist = hlist->next)
        printf("%d ", hlist->num);
    printf("\n");
}

void print_list2(struct list_node *hlist)
{
    for (; hlist->next; hlist = hlist->next)
        ;
    for (; hlist; hlist = hlist->prev)
        printf("%d ", hlist->num);
    printf("\n");
}



void front_back_split(node_t *head, node_t **back)
{
    if (!head || !back)
    {
        return;
    }

    node_t *b = head;

    while (head->next && head->next->next)
    {
        b = b->next;
        head = head->next->next;
    }

    *back = b->next;
    (*back)->prev = NULL;
    b->next = NULL;
}


int comparator_int(const void *p, const void *q)
{
    const int *a = p;
    const int *b = q;
    return *a - *b;
}


node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *))
{
    if (!head_a || !head_b)
    {
        return NULL;
    }
	
    if (comparator == NULL)
    {
        return NULL;
    }

    node_t *a = *head_a;
    node_t *b = *head_b;
    node_t *head = NULL;
    node_t *c = NULL;

    if (a || b)
    {
        if (!b || (a && comparator(&(a->num), &(b->num)) < 0))
        {
            head = a;
            c = head;
            a = a->next;
        }
        else if (b)
        {
            head = b;
            c = head;
            b = b->next;
        }
    }

    while (a && b)
    {
        if (comparator(&(a->num), &(b->num)) < 0)
        {
            c->next = a;
            c->next->prev = c;
            c = c->next;
            a = a->next;
        }
        else
        {
            c->next = b;
            c->next->prev = c;
            c = c->next;
            b = b->next;
        }
    }

    while (a)
    {
        c->next = a;
        c->next->prev = c;
        c = c->next;
        a = a->next;
    }

    while (b)
    {
        c->next = b;
        c->next->prev = c;
        c = c->next;
        b = b->next;
    }

    a = NULL;
    b = NULL;
    c = NULL;
    *head_a = NULL;
    *head_b = NULL;

    return head;
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    if (!head || !head->next)
    {
        return head;
    }

    if (!comparator)
    {
        return NULL;
    }

    node_t *a = NULL;
    node_t *b = NULL;
    node_t *back = NULL;
    node_t *new_head = NULL;

    front_back_split(head, &back);
    a = sort(head, comparator);
    b = sort(back, comparator);

    new_head = sorted_merge(&a, &b, comparator);

    return new_head;
}




int main()
{
    int b1 = 5;
    int b2 = 2;
    int b3 = 1;
    int b4 = 3;
    int b5 = 4;

    node_t *n1 = malloc(sizeof(node_t));
    if (!n1)
        return -1;
    node_t *n2 = malloc(sizeof(node_t));
    if (!n2)
    {
        free(n1);
        return -1;
    }
    node_t *n3 = malloc(sizeof(node_t));
    if (!n3)
    {
        free(n1);
        free(n2);
        return -1;
    }
    node_t *n4 = malloc(sizeof(node_t));
    if (!n4)
    {
        free(n1);
        free(n2);
        free(n3);
        return -1;
    }
    node_t *n5 = malloc(sizeof(node_t));
    if (!n5)
    {
        free(n1);
        free(n2);
        free(n3);
        free(n4);
        return -1;
    }
    n1->num = b1;
    n2->num = b2;
    n3->num = b3;
    n4->num = b4;
    n5->num = b5;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    n1->prev = NULL;
    n2->prev = n1;
    n3->prev = n2;
    n4->prev = n3;
    n5->prev = n4;

    n1 = sort(n1, comparator_int);
    print_list(n1);
    print_list2(n1);
}