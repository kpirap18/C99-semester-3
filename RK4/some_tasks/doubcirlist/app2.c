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
    node->prev= hlist;
    node->next = NULL;

    return hlist;
}

struct list_node* add_front(struct list_node *hlist, struct list_node *node)
{
    node->next = hlist;
    node->prev= NULL;
    
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
        }
        else
        {
            temp = cur;
            cur = cur->next;
        }
    }

    return del;
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
        return NULL;
    
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
    for (; hlist; hlist = hlist->prev)
        printf("%d ", hlist->num);
    printf("\n");
}

int main()
{

    int b1 = 1;
    int b2 = 2;
    int b3 = 3;
    int b4 = 4;
    int b5 = 5;

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

    n1->next = NULL;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    n1->prev = NULL;
    n2->prev = n1;
    n3->prev = n2;
    n4->prev = n3;
    n5->prev = n4;

    n1 = del_by_value(n1, 1);
    //printf("\n hlist->num = %d \n", n1->num);
    if (n1)
    {
        printf("\n List after deleting \n");
        print_list(n1);
    }
    else
        printf("\n List is empty\n");

    { // 1
        int b1 = 1;
        int b2 = 2;
        int b3 = 3;
        int b4 = 4;
        int b5 = 5;

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

        //print_list(n1);
        n1 = del_by_value(n1, 1);
        if (n1->num == b2)
        {
            printf("TEST 1 PASTED\n");
        }
        else
        {
            printf("TEST 1 FAILED\n");
        }
        //print_list(n1);
        //print_list2(n5);
    }

    { // 2
        int b1 = 1;
        int b2 = 2;
        int b3 = 3;
        int b4 = 4;
        int b5 = 5;

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

        //print_list(n1);
        n1 = del_by_value(n1, 2);
        if (n1->next->num == b3)
        {
            printf("TEST 2 PASTED\n");
        }
        else
        {
            printf("TEST 2 FAILED\n");
        }
        //print_list(n1);
        //print_list2(n5);
    }

    { // 3
        int b1 = 1;


        node_t *n1 = malloc(sizeof(node_t));
        if (!n1)
            return -1;

        n1->num = b1;

        n1->next = NULL;

        n1->prev = NULL;

        //print_list(n1);
        n1 = del_by_value(n1, 1);
        if (n1 == NULL)
        {
            printf("TEST 3 PASTED\n");
        }
        else
        {
            printf("TEST 3 FAILED\n");
        }
        //print_list(n1);
        //print_list2(n5);
    }

    { // 4
        int b1 = 1;
        int b2 = 2;
        int b3 = 3;
        int b4 = 4;
        int b5 = 5;

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

        //print_list(n1);
        n1 = del_by_value(n1, 5);
        if (n4->next == NULL)
        {
            printf("TEST 4 PASTED\n");
        }
        else
        {
            printf("TEST 4 FAILED\n");
        }
        //print_list(n1);
        //print_list2(n5);
    }

}